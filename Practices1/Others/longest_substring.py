"""Edabit qn
Given a string of digits, return the longest substring with alternating odd/even or even/odd digits.
If two or more substrings have the same length, return the substring that occurs first.
Examples:
longest_substring("225424272163254474441338664823") ➞ "272163254"
# substrings = 254, 272163254, 474, 41, 38, 23

longest_substring("594127169973391692147228678476") ➞ "16921472"
# substrings = 94127, 169, 16921472, 678, 476

longest_substring("721449827599186159274227324466") ➞ "7214"
# substrings = 7214, 498, 27, 18, 61, 9274, 27, 32
# 7214 and 9274 have same length, but 7214 occurs first."""

def streak(d1, d2):
	return (int(d1) % 2 == 0 and int(d2) % 2 != 0) or (int(d2) % 2 == 0 and int(d1) % 2 != 0)

def longest_substring(digits):
    alter_ss = ""
    alter_ss_lst = []
    for i in range(0, len(digits)-1):
        if streak(digits[i], digits[i+1]):
            alter_ss += digits[i]
        elif alter_ss and not streak(digits[i], digits[i+1]):
            alter_ss += digits[i]
            alter_ss_lst.append(alter_ss)
            alter_ss = ""
    print(alter_ss_lst)
    longest = 0
    longest_string = ''
    for s in alter_ss_lst:
        if len(s) > longest:
            longest = len(s)
            longest_string = s
    return longest_string


if __name__=="__main__":
    print(longest_substring("754388489999793138912431545258"))