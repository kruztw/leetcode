# ref:https://medium.com/@Kadai/%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8B%E5%A4%A7%E4%BE%BF%E7%95%B6-bloom-filter-58b0320a346d

import bitarray
import hashlib
import random
import string
import sys
import time

class bf:
    def __init__(self, size):
        self.size = size
        self.bitarray = bitarray.bitarray(size)
        self.bitarray.setall(False)
        self.hash_functions = [hashlib.md5, hashlib.sha1, hashlib.sha224]
        
    def add_data(self, data):
        for hash_func in self.hash_functions:
            index = int(hash_func(data).hexdigest(), 16) % self.size
            self.bitarray[index] = 1

    def is_data_exist(self, data):
        result = bitarray.bitarray([True])
        for hash_func in self.hash_functions:
            index = int(hash_func(data).hexdigest(), 16) % self.size
            result &= self.bitarray[index:index+1]

        if result[0]:
            return True
        else:
            return False

if __name__ == "__main__":
    bf_size = 10000
    bf_contain_data_size = 1000
    test_case_amount = 1000
    random.seed(time.time())

    b = bf(bf_size)
    s = set()
    d = {}

    for i in range(bf_contain_data_size):
        data = ''.join(random.choice(string.ascii_uppercase) for _ in range(10))
        data = str.encode(data)
        b.add_data(data)
        s.add(data)
        d[data] = 1

    false_positive_amount = 0

    for i in range(test_case_amount):
        data = ''.join(random.choice(string.ascii_uppercase) for _ in range(10))
        data = str.encode(data)
        if b.is_data_exist(data) ^ (data in s):
            false_positive_amount += 1

    fail_rate = round((false_positive_amount / test_case_amount) * 100, 2)
    print("{:20} {}\n".format("success case amount:", test_case_amount - false_positive_amount))
    print("{:20} {}\n".format("fail case amount:", false_positive_amount))
    print("{:20} {}%\n".format("fail rate:", fail_rate))
    print("{:20} {} bytes\n".format("bf bitarray size:", sys.getsizeof(b.bitarray.tobytes())))