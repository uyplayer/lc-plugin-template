
def traverse(array:list,index:int):

    if len(array) == index:
        return 

    traverse(array,index+1)
    print(array[index])

def vector_traverse():

    array = [1,2,3,4,5,6,7,8,9,63,234,43,554,65,7,3244,24,23]
    traverse(array,0)


if __name__ == "__main__":
    vector_traverse()