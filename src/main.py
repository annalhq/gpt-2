# refernce implementation in python (currently incomplete)

import tiktoken


f = open("tiny.txt", "r")
enc = tiktoken.encoding_for_model("gpt2")

tokens = enc.encode(f.read())  # encoding
text = enc.decode(tokens)  # decode it back to original

print(tokens)
