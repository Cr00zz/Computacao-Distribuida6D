from flask import Flask
import requests


dolar = 5.22
euro = 5.09

app = Flask(__name__)


@app.route("/convertemoeda",methods=['GET'])
def paginaInicial():
  return "Insira um valor na barra de pesquisa (em reais) para converter em dolar e euro",200

@app.route('/convertemoeda/<float:valor>',methods=['GET'])
def convertermoeda(valor):
  real = float(valor)
  data ={
    "real": real,
    "dolar": real/dolar,
    "euro":real/euro 
  }
  return data

if __name__ == "__main__":
  app.run()
  
