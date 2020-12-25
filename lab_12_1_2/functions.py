import ctypes

# C array library
array_lib = ctypes.CDLL("lib/libarray.so")

# Array shift func
array_shift_left = array_lib.array_shift_left
array_shift_left.argtypes = (
    ctypes.POINTER(ctypes.c_int),
    ctypes.c_size_t,
    ctypes.c_size_t,
)
array_shift_left.restype = ctypes.c_void_p

# Array fill full squares func
array_fill_full_squares = array_lib.array_fill_full_squares
array_fill_full_squares.argtypes = (
    ctypes.POINTER(ctypes.c_int),
    ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_int),
)
array_fill_full_squares.restype = ctypes.c_int


def list_shift_left(data, shift):
    list_len = len(data)
    c_array = (ctypes.c_int * list_len)(*data)

    array_shift_left(c_array, list_len, shift)

    return list(c_array)


def list_filter_full_squares(data):
    src_list_len = len(data)
    c_src_array = (ctypes.c_int * src_list_len)(*data)

    result_len = int(array_fill_full_squares(c_src_array, src_list_len, None))
    c_array_result = (ctypes.c_int * result_len)(*([0] * result_len))

    array_fill_full_squares(c_src_array, src_list_len, c_array_result)

    return list(c_array_result)
