#define MAX_SIZE 10
void matrix_mult(int size);
void matrix_io_driver();
void get_matrix(int size, int matrix[10][10]);
int get_matrix_size();
int calculate_determinant(int size, int matrix[10][10]);
void matrix_add_sub(int size, int(*func)(int, int));
void cal_det_io(int size);
