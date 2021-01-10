class Sentence:

    def __init__(self, sentence):
        self.sentence = sentence
        self.index = 0
        self.words = self.sentence.split()

    def __iter__(self):
        return self

    def __next__(self):
        if self.index >= len(self.words):
            raise StopIteration
        index = self.index
        self.index += 1
        return self.words[index]

def generator(sentence):
    for word in sentence.split():
        yield word

# my_sentence = Sentence('This is a test')

my_sentence = generator('This is a test')

print(next(my_sentence))
print(next(my_sentence))

# for word in my_sentence:
#     print(word)