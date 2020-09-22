from chatterbot import ChatBot
from chatterbot.trainers import ListTrainer
import spacy
nlp=spacy.load('en_core_web_sm')

bot = ChatBot("My Bot")

convo = [
    'hello',
    'hi there !',
    'what is your name ?',
    'My name is Bot , i am created by Durgesh',
    'how are you ?',
    'I am doing great these days',
    'thank you',
    'In which city you live ?',
    'I live in lucknow',
    'In which language you talk?',
    ' I mostly talk in english'
]

trainer = ListTrainer(bot)

# now training the bot with the help of trainer

trainer.train(convo)

# answer = bot.get_response("what is your name?")
# print(answer)

print("Talk to bot ")
while True:
    query = input()
    if query == 'exit':
        break
    answer = bot.get_response(query)
    print("bot : ", answer)