from flask import Flask, url_for
app=Flask(__name__)

@app.route('/')
def hello_world():
	return 'Hello World!'


@app.route('/hello')
def hello():
	return 'hello'

@app.route('/user/<username>')
def show_user_name(username):
	return 'UserName %s' % username 

@app.route('/post/<int:post_id>')
def show_post(post_id):
	return 'PostId: %d' % post_id

with app.test_request_context():
	print url_for('show_user_name',username="John Doe")

'''

if __name__=='__main__':
	app.run(host='0.0.0.0')
	public ip
	app.run(debug=True)
	open debug
'''

if __name__=='__main__':
	app.run(debug=True)

