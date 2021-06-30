from flask import Flask         # flask=framework, Flask= Python  class
                                         # web application instance 생성
app=Flask(__name__)             # __name__  문자열 __main__을 갖는 변수

@app.route(‘/’)                 # route :  함수와 URL을 연결, 함수를 호출함
def index():
     return ‘Hello My world’
@app.route(‘/sub1’)
def  sub1();
     return ‘Hello My App’

if __name__==‘__main__’:
     app.run(debug=True, host=‘127.0.0.1’, port=5000)
     #app.run(debug=True, host='0.0.0.0', port=5000)