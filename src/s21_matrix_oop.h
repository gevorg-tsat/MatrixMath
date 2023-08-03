

class S21Matrix {
    private:
        // Attributes
        int rows, cols;
        double **matrix_;

    public:
        S21Matrix();                                                // default constructor
        S21Matrix(int rows, int cols);                              // parameterized constructor
        S21Matrix(const S21Matrix& other);                              // copy cnstructor
        S21Matrix(S21Matrix&& other);                                   // move cnstructor
        ~S21Matrix();             // Destructor

        void sumMatrix(const S21Matrix& other); 
        bool eqMatrix(const S21Matrix& other);
        void sumMatrix(const S21Matrix& other);
        void subMatrix(const S21Matrix& other);
        void mulNumber(const double num);
        void mulMatrix(const S21Matrix& other);
        S21Matrix transpose();
        S21Matrix calcComplements();
        double determinant();
        S21Matrix inverseMatrix();

        S21Matrix operator+(const S21Matrix& other) const;
        S21Matrix operator-(const S21Matrix& other) const;
        S21Matrix operator*(const S21Matrix& other) const;
        S21Matrix operator*(double num) const;

        S21Matrix &operator+=(const S21Matrix& other);
        S21Matrix &operator-=(const S21Matrix& other);
        S21Matrix &operator*=(const S21Matrix& other);
        S21Matrix &operator*=(double num);

        S21Matrix &operator=(const S21Matrix &other);
        S21Matrix &operator=(S21Matrix &&other) noexcept;

        bool operator==(const S21Matrix &other) const;
        double &operator()(int i, int j);
        const double &operator()(int i, int j) const;
};