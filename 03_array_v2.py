import ctypes


class Array:
    def __init__(self, size):
        array_data_type = ctypes.py_object * size
        self.size = size
        self.memory = array_data_type()
        for i in range(size):
            self.memory[i] = None
    
    def __len__(self):
        return self.size
    
    def __getitem__(self, idx):
		# Is valid idx?
        return self.memory[idx] 
    
    def __setitem__(self, idx, value):
        self.memory[idx] = value

    def __repr__(self):
        result = ''
        for i in range(self.size):
            result += str(self.memory[i]) + ', '
        return result



if __name__ == '__main__':
    array = Array(6)

    for i in range(len(array)):
        array[i] = i + 1

    for i in range(len(array)):
        print(array[i], end=', ')
    print()
    # 1, 2, 3, 4, 5, 6,

    print(array)    # uses __repr__

