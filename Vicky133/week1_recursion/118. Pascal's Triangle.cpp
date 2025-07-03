class Solution {
public:
    int nCr(int n,int r){
        long long res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return (int)res;
    }

    int pascal(int row, int col){
        if(col==0||col==row)return 1;
        return (pascal(row-1,col-1)+pascal(row-1,col));
    }
    vector<vector<int>> generate(int num) {
        // 1 Recursion
        vector<vector<int>>triangle;
        for(int i=0;i<num;i++){
            vector<int>rows;
            for(int j=0;j<=i;j++){
                rows.push_back(pascal(i,j));
            }
            triangle.push_back(rows);
        }
        return triangle;

    }
};