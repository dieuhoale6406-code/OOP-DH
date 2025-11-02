class Point {
    //public, private, protected
    //tập tên thuộc tinh
    public:
        int xVal;
        int yVal;
    //tap hợp nguyen mau ham thanh vien
    public:
        //Default Constructor
        Point();
        //Copoy constructor
        Point(const Point&);

        Point(const int&, const int&);
        //Destructor - hàm hủy
        ~Point();
        void TT(int);
        void Show();
        //get
        int Get_xVal();
        //get
        void Set_xVal(const int&);
};