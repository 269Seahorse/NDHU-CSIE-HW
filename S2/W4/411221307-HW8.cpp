struct p{
    double x;
    double y;
};

class Path{
public:
    Path(Segment *seg, int n){
        p a[500];
        int m = 0;
        double sum = 0;
        bool cir = 0;
        for(int i = 0; i < n; i++){
            sum += seg[i].length();
            for(int j = 0; j < i; j++)
                if((seg[i].getEnd(1).getX() == a[j].x && seg[i].getEnd(1).getY() == a[j].y) || (seg[i].getEnd(0).getX() != seg[i - 1].getEnd(1).getX() && seg[i].getEnd(0).getY() != seg[i - 1].getEnd(1).getY() && i > 0)){
                    cout << "-1\n";
                    cir = 1;
                    break;
                }
            a[i].x = seg[i].getEnd(0).getX();
            a[i].y = seg[i].getEnd(0).getY();
        }
        if(!cir) cout << sum << endl;
    }
};