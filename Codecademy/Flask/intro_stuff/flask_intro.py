from flask import Flask

app = Flask(__name__)


@app.route('/')
@app.route('/home')
def home():
    return '<h1>Hello, World!</h1>'


@app.route('/reporter/<int:reporter_id>')
def reporter(reporter_id):
    return f'''
    <h2>Reporter {reporter_id} Bio</h2>
    <a href="/">Return to home page</a>
    '''

@app.route('/article/<article_name>')
def article(article_name):
  #replace hypens with spaces
  article_name = " ".join(article_name.split("-"))
  #Title Case 'article_name'
  article_name = str.title(article_name)

  return f"""
  <h2>{article_name}</h2>
  <a href='/'> Return back to home page </a>
  """
