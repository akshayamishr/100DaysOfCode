from flask import Flask, jsonify
import openai

app = Flask(__name__)

api_key = "sk-Sqf6Z4TfIjzIP4Fkue4ET3BIbkFJXM2Aqn1KSqwQVEHsjhEA"
openai.api_key = api_key

@app.route('/api/hello', methods=['GET'])
def hello():
    return jsonify({'message': 'Hello, this is your REST API'})

if __name__ == '__main__':
    # app.run()

    question = "1 + 1"

    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": question},
        ]
    )
    print(response)
