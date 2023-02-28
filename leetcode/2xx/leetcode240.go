/*
https://leetcode.cn/problems/search-a-2d-matrix-ii/
*/

package main

import "fmt"

func FindHalfPos(matrix [][]int, cols int, col int, rows int, row int, target int) (int, int) {
	midcol := (cols + col) / 2
	midrow := (rows + row) / 2
	if midcol == cols && midrow == rows || midcol == col && midrow == row {
		return midcol, midrow
	}
	if matrix[midcol][midrow] == target {
		return midcol, midrow
	}
	if matrix[col][row] > target {
		return FindHalfPos(matrix, cols, midcol, rows, midrow, target)
	} else {
		return FindHalfPos(matrix, midcol, col, midrow, row, target)
	}
	return 0, 1
}

func searchMatrix(matrix [][]int, target int) bool {
	col := len(matrix)
	row := len(matrix[0])
	posCol, posRow := FindHalfPos(matrix, 0, col-1, 0, row-1, target)
	fmt.Println(posCol, posRow)
	return false
}

func main() {
	matrix := [][]int{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}
	target := 5
	searchMatrix(matrix, target)
}
