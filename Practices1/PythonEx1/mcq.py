class Question:
    def __init__(self, prompt, answer):
        self.prompt = prompt
        self.answer = answer

question_prompts = [
    "What is the colour of trees?\n(a) Green\n(b) Blue\n(c) Red\n",
    "What is the length of 1m in cm?\n(a) 1000cm\n(b) 100cm\n(c) 10cm\n",
    "How many bytes do an integer contains?\n(a) 4 bytes\n(b) 16 bytes\n(c) 32 bytes\n"
]

questions = [
    Question(question_prompts[0], 'a'),
    Question(question_prompts[1], 'b'),
    Question(question_prompts[2], 'a')
]

def run_test(questions):
    score = 0
    for question in questions:
        while True:
            guess = input(question.prompt)
            if guess.lower() not in 'abc':
                print("Invalid input.")
            else:
                break
        if guess.lower() == question.answer:
            score += 1
    print("You got {}/{} correct!".format(score, len(questions)))

run_test(questions)