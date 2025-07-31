#if !defined(PASCALS_TRIANGLE_H)
#define PASCALS_TRIANGLE_H
#include <cstddef>
#include <vector>
namespace pascals_triangle {
    inline std::vector<std::vector<int>> generate_rows(size_t rows_count) {
        if(rows_count == 0) 
            return {};
        if(rows_count == 1) 
            return {{1}};
        if(rows_count == 2) 
            return {{1}, {1, 1}};
        std::vector<std::vector<int>> triangle{{1}, {1, 1}};
        triangle.resize(rows_count);
        for(size_t i = 2; i < rows_count; ++i) {
            triangle[i].resize(i + 1);
            triangle[i].front() = 1;
            triangle[i].back() = 1;
            for(size_t j = 1; j < triangle[i].size() - 1; ++j) 
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        return triangle;
    }
}  // namespace pascals_triangle

#endif // PASCALS_TRIANGLE_H