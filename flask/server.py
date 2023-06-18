# Replace <password> with your MongoDB Atlas password
from pymongo import MongoClient

connection_string = "mongodb+srv://hariharan2604:hariHARAN-2604@atlastest.a6oo0uf.mongodb.net/?retryWrites=true&w=majority"

# Connect to MongoDB Atlas
client = MongoClient(connection_string)

# Access the sample.airbnb database
db = client['sample_airbnb']

# Access the listingsAndReviews collection
collection = db['listingsAndReviews']

# Find the first 5 documents
results = collection.find().limit(5)

# Iterate over the documents
for result in results:
    print(result)