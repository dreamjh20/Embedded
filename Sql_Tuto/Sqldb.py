import sqlite3
print('sqlite3.version:', sqlite3.version)
import datetime as dt

now = dt.datetime.now()
print('now time: ', now)

nowDatetime = now.strftime('%Y-%m-%d %H:%M:%S')
print('now time: ', nowDatetime)

conn = sqlite3.connect('testdb.db', isolation_level=None)