# import datetime as dt

# now = dt.datetime.now()
# my_bday = dt.date(1996, 4, 23)

# today = dt.date.today()
# # print(today)
# print(my_bday.year)

from datetime import datetime
import pytz

local = datetime.now()
print("Local:", local.strftime("%m/%d/%Y, %H:%M:%S"))

tz_SG = pytz.timezone('Asia/Singapore')
datetime_SG = datetime.now(tz_SG)
print("SG:", datetime_SG.strftime("%m/%d/%Y, %H:%M:%S"))

tz_London = pytz.timezone('Europe/London')
datetime_London = datetime.now(tz_London)
print("London:", datetime_London.strftime("%m/%d/%Y, %H:%M:%S"))