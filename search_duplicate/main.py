import os
import time

from models.hash_functions import crc, pjw, buz
from models.search import search_duplicate

path = "data/"
files = [path + file for file in os.listdir(path) if file.endswith(".txt")]
hashes = [crc, pjw, buz, hash]
print("---------------------------------")
for hash in hashes:
    start_time = time.time()
    duplicates = search_duplicate(files, hash)
    end_time = time.time()
    print(f"function: {hash.__name__}")
    print(f"count of duplicates: {len(duplicates)}")
    print(f"time: {end_time - start_time} seconds")
    print("---------------------------------")