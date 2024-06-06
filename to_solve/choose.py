import random
path = "/to_solve"
questions = []
q = input("Input number of the questions to solve:")
with open("path", mode = 'r') as file:
  for i, line in enumerate(file):
    questions.append([str(line), i])

  
try:
  L = random.sample(range(0, len(questions)-1), q)
  for i in range(L):
    print(*questions[i])
except ValueError:
  for l in questions:
    print(*l)

