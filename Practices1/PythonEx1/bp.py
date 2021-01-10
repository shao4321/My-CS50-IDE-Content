# Check for balanced parentheses using stack

def check_balanced_paren(string):

    def exp_check(exp1, exp2):
        if exp1 == '(' and exp2 == ')':
            return True
        elif exp1 == '{' and exp2 == '}':
            return True
        elif exp1 == '[' and exp2 == ']':
            return True
        else:
            return False

    exp_list = []

    for i in string:
        if (i == '(') or (i == '{') or (i == '['):
            exp_list.append(i)
        if (i == ')') or (i == '}') or (i == ']'):
            if (string == "") or (exp_check(exp_list[-1], i) == False):
                return False
            else:
                exp_list.pop()
    if exp_list == []:
        return True
    else:
        return False

print(check_balanced_paren("("))