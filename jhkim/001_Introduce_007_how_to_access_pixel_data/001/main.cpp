// cd /mnt/1T-5e7/mycodehtml/cpp_tutorial/jesyspa/03_If && \
// g++ \
// -o main /mnt/1T-5e7/mycodehtml/cpp_tutorial/jesyspa/03_If/main.cpp && \
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
// Ways which you can use to access to pixel

// 1. "At" approach
// 2. "Ptr" approach
// 3. "Data" approach
// 4. "Iterator" approach

// ======================================================================
// 1. At approach

// Mat image (row,column,CV_TYPE);
// image.at (row_you_want_to_access,column_you_want_to_access);

// Advantage: at() accesses to the pixel after a validation process, 
// so using at() is safe and accurate.

// Disadvantage: at() is most slow than other 3 ways.

// ======================================================================
// 2. Ptr approach

// Mat image (row,column,CV_TYPE);
// image.ptr (row_you_want_to_access,column_you_want_to_access);
// Above accessing is converted to the pointer

// Advantage: 
// Accessing speed to the pixel is faster than using at().

// Disadvantage: 
// - ptr directly accesses to pixel
// - But ptr is still slower than "data" approach
// - And using ptr is difficult to learn and use.

// ======================================================================
// 3. Data approach (using pointer)

// Mat image (row,column,CV_TYPE);
// DATA_TYPE * data = (DATA_TYPE *) image.data;data [WANT_ROW * image.cols + WANT_COL]

// - ROW: Row
// - COL: Column
// - CV_TYPE: data type ( for example : CV_8UC3 = 8 bit 3 channels)
// - DATA_TYPE: Mat creation data type ( for example : float, usigned char)
// - WANT_ROW: access to the desired row
// - WANT_COL: access to the desired column

// Advantage: very fast.
// Disadvantage: this way directly accesses to the pixle by using pointer.
// So, this way is weak in the error checking.
// If you write the address in the pointer,
// runtime error will happen.
