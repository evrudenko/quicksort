import random

def create_intdata(d_from, d_to, amount):
	return [random.randint(d_from, d_to) for i in range(amount)]

def create_floatdata(d_from, d_to, amount):
	return [round(random.random() * (d_to - d_from) + d_from, 4) for i in range(amount)]

def main():
	data = create_intdata(1, 1000, 200)

	f = open('array.txt', 'w')

	f.write(str(data));

if __name__ == '__main__':
	main()

# Сейтшвик..