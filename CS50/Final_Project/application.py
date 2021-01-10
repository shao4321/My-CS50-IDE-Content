import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime
from pytz import timezone

from helper import apology, login_required

# Retrieving my timezone
fmt = "%Y-%m-%d %H:%M:%S"
now_utc = datetime.now(timezone('Asia/Singapore'))

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///expense.db")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register a new user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        # Prompting user for their informations
        username = request.form.get("username")
        password = request.form.get("password")
        cfm_pw = request.form.get("cfm_password")

        '''# Require users’ passwords to have at least 2 letters, numbers, and 1 symbol
        letters2 = False
        symbol1 = False
        count = 0
        for i in password:
            if i.isalpha() == True:
                count += 1
            if count == 2:
                letters2 = True
                break
        if set('[~!@#$%^&*()_+{}":;\']+$').intersection(password):
            symbol1 = True
        if letters2 == False:
            return apology("Sorry, your password requires at least 2 alphabets")
        if symbol1 == False:
            return apology("Sorry, your password requires at least 1 symbol")'''

        # Error checking and storing user's information
        if password != cfm_pw:
            return apology("Sorry, your password does not match your confirm password.")
        elif not username:
            return apology("Please enter a username.")
        elif not password or not cfm_pw:
            return apology("Please enter a password.")
        else:
            # Hashing the password
            pw_hash = generate_password_hash(password)
            try:
                db.execute("INSERT INTO users(username, hash) VALUES (:username, :hash)", username=username, hash=pw_hash)
            except RuntimeError:
                return apology("Sorry, your username has been used.")
            finally:
                flash('Registered Succesfully!')
                return render_template("login.html")

@app.route("/")
@login_required
def index():
    """Show total savings and expenditure for each individual months and total"""

    # Querying for the user's infos for the current month
    dateTime = datetime.now()
    month = dateTime.strftime("%B")
    na = '-'
    rows = db.execute("SELECT id, income, budget, spent, balance_bg, balance_ic, balance_save FROM overview WHERE users_id=:userid AND months=:month",
    userid=session["user_id"], month=month)

    return render_template("index.html", rows=rows, month=month, na=na)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("Must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("Must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("Invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        flash('You were successfully logged in')
        return redirect(url_for('index'))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    flash('You were successfully logged out')
    return render_template("login.html")


@app.route("/change_password", methods=["GET","POST"])
@login_required
def changepassword():
    """Allow users to change their passwords"""
    if request.method == "GET":
        return render_template("changePW.html")
    else:
        # Prompting user to key in their old PW
        oldpassword = request.form.get("oldpassword")

        # Error checking
        if not oldpassword:
            return apology("Please enter a password.")

        # Query database for user hash password
        rows = db.execute("SELECT hash FROM users WHERE id = :userid",userid=session["user_id"])

        # Ensure old password entered is correct
        if not check_password_hash(rows[0]["hash"], oldpassword):
            return apology("Invalid old password", 403)

        newpassword = request.form.get("newpassword")
        cfm_newpassword = request.form.get("cfm_newpassword")

        # Error checking
        if cfm_newpassword != newpassword:
            return apology("Sorry, your password does not match your confirm password.")
        elif not newpassword or not cfm_newpassword:
            return apology("Please enter a password.")

        # Hash the new password
        newpassword_hash = generate_password_hash(newpassword)

        # Update hash in SQL
        db.execute("UPDATE users SET hash=:hashed WHERE id=:userid",
        hashed=newpassword_hash, userid=session["user_id"])

        # Return to homepage
        flash('Password Changed!')
        return redirect(url_for('index'))


@app.route("/new_income", methods=["GET", "POST"])
@login_required
def newIC():
    """Create new income"""

    if request.method == "GET":
        return render_template("new_income.html")
    else:

        # Get the income value
        try:
            income = request.form.get("income")
            '''if not income or income < 0:
                return apology("Please enter an appropriate value.")'''
        except:
            return apology("Please enter an appropriate value.")
        else:
            month = datetime.now()
            db.execute("INSERT INTO overview(users_id,months,income) VALUES(:userid,:months,:income)",
            userid=session["user_id"], months=month.strftime("%B"), income=int(income))
            flash('Income created!')
            return redirect(url_for('index'))


@app.route("/del_income", methods=["GET", "POST"])
@login_required
def delIC():
    """Delete existing income"""

    if request.method == "GET":
        return render_template("del_income.html")
    else:

        # Get the income value
        try:
            month = request.form.get("month")
            idno = request.form.get("idno")
            '''if not income or income < 0:
                return apology("Please enter an appropriate value.")'''
        except:
            return apology("Please enter an appropriate value.")
        else:
            db.execute("DELETE FROM overview WHERE users_id=:userid AND month=:month AND idno=:idno",
            userid=session["user_id"], month=month, idno=idno)
            flash('Income deleted!')
            return redirect(url_for('index'))


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("Pending codes")
    '''# Querying for the stocks user has bought/sold
    rows_transac = db.execute("SELECT * FROM transactions WHERE userid=:userid",userid=session["user_id"])
    rows_cashtransac = db.execute("SELECT * FROM cashtransac WHERE userid=:userid",userid=session["user_id"])
    return render_template("history.html", rows_transac=rows_transac, rows_cashtransac=rows_cashtransac)'''


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
