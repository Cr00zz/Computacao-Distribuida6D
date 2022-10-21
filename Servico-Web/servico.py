from flask import Flask
from flask import jsonify
from flask import request

dolar = 5.22
euro = 5.09

app = Flask(__name__)

array_conversao = []

@app.route('/convertemoeda',methods=['GET'])
def getTodasConversao():
    return jsonify({'conversoes: \n':array_conversao})

@app.route('/convertemoeda',methods=['POST'])
def criaJsonMoeda():
    real_dolar = request.json['real']*dolar
    real_euro = request.json['real']*euro
    data = {
        'conversao': {
        'real': request.json['real'],
        'dolar': real_dolar,
        'euro': real_euro,
        }
    }
    array_conversao.append(data)
    return jsonify(data)

if __name__ == '__main__':
  app.run()
