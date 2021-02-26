#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX

#define maximum 10

class spm
{
private:
	int r, c, v;
public:
	void read(spm* a);
	bool search(spm* a, int key);
	void display(spm* a);
	void displayMatrix(spm* a);
	void transpose(spm* a, spm* b);
	void fastTranspose(spm* a, spm* b);
};

#endif
