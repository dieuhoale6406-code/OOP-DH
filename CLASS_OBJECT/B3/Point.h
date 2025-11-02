//Khai báo lớp
class Point {
    //public, private, protected: phạm vi sử dụng là đến khi gặp kiểu mới (public, private,protected) hoặc đến khi gặp } )
    //tập tên thuộc tính
    public:
        int xVal;
        int yVal;
        const int z;
        static int n;
        const static int m = 0;
    //tập hợp nguyên mẫu hàm thành viên
    public:
        //Constructor - hàm dựng
        // Default Constructor
        // Point();
        // Copy Constructor
        Point(const Point&);
        Point(const int& = 1,const int& = 1);
        //Destructor - hàm hủy
        ~Point();
        void TT(int);
        void show();
        int Get_xVal();
        int Get_yVal();
        void Set_xVal(const int&);
        static void Shown();
};