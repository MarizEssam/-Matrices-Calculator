#include <iostream>
using namespace std;

void showMenu() {
	cout << "Calculator menu:" << endl;
	cout << "1. Show matrix value" << endl;
	cout << "2. Add matrices" << endl;
	cout << "3. Subtract matrices" << endl;
	cout << "4. Multiply matrices" << endl;
	cout << "5. Divide matrices" << endl;
	cout << "6. Transpose matrix" << endl;
}

int main() {
	int m1 = 0, n1 = 0, m2 = 0, n2 = 0, m3 = 0, n3 = 0, m4 = 0, n4 = 0;
	char symb;
	string matrixName;
	float mat1[90], mat2[90], var[90], det;
	float matrix1[90][90], matrix2[90][90], matrix2adj33[90][90], matrix2adj22[90][90], variable[90][90], variableadj[90][90];
	float inverse[90][90], result[90][90], resultdiv[90][90];

	cout << "Welcome to the matrix calculator!" << endl << endl;
	cout << "* Please initialize your matrix as following: A = [1.2 2.2 3.1; -4.5 5.4 6.3; 2.3 5.2 4.7]" << endl;
	cout << "* where the semicolons separate the rows" << endl << endl;

	//matrix1
	//any matrix to 1D array
	cout << "enter numebr of matrix1 rows: " << flush;
	cin >> m1;
	cout << "enter number of matrix1 columns: " << flush;
	cin >> n1;
	cout << "Enter your  first matrix here: " << flush;
	cin >> matrixName >> symb >> symb;
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			cin >> mat1[j + i * n1];
		} cin >> symb;
	}

	//any 1D array to 2D array
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			matrix1[i][j] = mat1[j];
			mat1[j] = mat1[j + (i + 1) * n1];
		}
	}

	//matrix2
	//any matrix to 1D array
	cout << endl << "enter numebr of matrix2 rows: " << flush;
	cin >> m2;
	cout << "enter number of matrix2 columns: " << flush;
	cin >> n2;
	cout << "and your second matrix is: " << flush;
	cin >> matrixName >> symb >> symb;
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++) {
			cin >> mat2[j + i * n2];
		} cin >> symb;
	}

	//any 1D array to 2D array
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++) {
			matrix2[i][j] = mat2[j];
			mat2[j] = mat2[j + (i + 1) * n2];
		}
	}
	cout << endl << "matrices entered successfully.." << endl << endl;

	int selection, i = 0;
	do {
		showMenu();
		cout << endl << "number of your choice is: " << flush;
		cin >> selection;

		switch (selection) {
		default:
			cout << "please select from the menu.." << endl;
			cout << endl << "number of your choice is: " << flush;
			cin >> selection;
		case 1:
			cout << "for matrix1 enter '1' for matrix2 enter '2' : " << flush;
			int choice;
			cin >> choice;
			if (choice == 1) {
				for (int i = 0; i < m1; i++) {
					for (int j = 0; j < n1; j++) {
						cout << matrix1[i][j] << "	";
					} cout << endl;
				} cout << endl;
			}
			else if (choice == 2) {
				for (int i = 0; i < m2; i++) {
					for (int j = 0; j < n2; j++) {
						cout << matrix2[i][j] << "	";
					} cout << endl;
				} cout << endl;
			}
			else {
				cout << "not valid.." << endl << endl;
			}
		case 2:
			if (m1 == m2 && n1 == n2 && selection == 2) {
				cout << "The two matrices are added successfully...!!\n";
				cout << "The new matrix will be :\n";
				for (int i = 0; i < m1; i++) {
					for (int j = 0; j < n1; j++) {
						result[i][j] = matrix1[i][j] + matrix2[i][j];
						cout << result[i][j] << " ";
					} cout << endl;
				}
				m4 = m1;
				n4 = n1;
			}
			else if (m1 != m2) {
				cout << "Oops.. the two matrices must have the same dimensions" << endl;
				return 0;
			}
			break;
		case 3:
			if (m1 == m2 && n1 == n2 && selection == 3) {
				cout << "showing result for subtracting matrix2 from matrix1: " << endl;
				for (int i = 0; i < m1; i++) {
					for (int j = 0; j < n1; j++) {
						result[i][j] = matrix1[i][j] - matrix2[i][j];
						cout << result[i][j] << " ";
					} cout << endl;
				}
				m4 = m1;
				n4 = n1;
			}
			else if (m1 != m2) {
				cout << "Oops.. the two matrices must have the same dimensions" << endl;
				return 0;
			}
			break;
		case 4:
			if (n1 == m2 && selection == 4) {
				for (int i = 0; i < m1; i++) {
					for (int j = 0; j < n2; j++) {
						result[i][j] = 0;
						for (int k = 0; k < n1; k++) {
							result[i][j] += matrix1[i][k] * matrix2[k][j];
						} cout << result[i][j] << "\t";
					} cout << endl;
				} cout << endl;
			}
			else {
				cout << "Oops.. number of matrix1 columns must be equal to number of matrix2 rows" << endl;
				return 0;
			}
			m4 = m1;
			n4 = n2;
			break;
		case 5:
			//to get the inverse of a 2D matrix

			if (n1 == m2 && selection == 5) {
				if (n1 == 3) {
					matrix2adj33[0][0] = matrix2[1][1] * matrix2[2][2] - matrix2[1][2] * matrix2[2][1];
					matrix2adj33[0][1] = -1 * (matrix2[1][0] * matrix2[2][2] - matrix2[1][2] * matrix2[2][0]);
					matrix2adj33[0][2] = matrix2[1][0] * matrix2[2][1] - matrix2[1][1] * matrix2[2][0];
					matrix2adj33[1][0] = -1 * (matrix2[0][1] * matrix2[2][2] - matrix2[2][1] * matrix2[0][2]);
					matrix2adj33[1][1] = matrix2[0][0] * matrix2[2][2] - matrix2[0][2] * matrix2[2][0];
					matrix2adj33[1][2] = -1 * (matrix2[0][0] * matrix2[2][1] - matrix2[0][1] * matrix2[2][0]);
					matrix2adj33[2][0] = matrix2[0][1] * matrix2[1][2] - matrix2[0][2] * matrix2[1][1];
					matrix2adj33[2][1] = -1 * (matrix2[0][0] * matrix2[1][2] - matrix2[0][2] * matrix2[1][0]);
					matrix2adj33[2][2] = matrix2[0][0] * matrix2[1][1] - matrix2[0][1] * matrix2[1][0];

					det = matrix2[0][0] * matrix2adj33[0][0] + matrix2[0][1] * matrix2adj33[0][1] + matrix2[0][2] * matrix2adj33[0][2];

					for (int i = 0; i < 3; i++) {                        //For storing adjoint in another 2-D Array
						for (int j = 0; j < 3; j++)
							inverse[i][j] = matrix2adj33[j][i];
					}
					for (int i = 0; i < 3; i++) {                       //For calculating inverse of matrix (2-D Array)
						for (int j = 0; j < 3; j++)
							inverse[i][j] = inverse[i][j] / det;
					}
					if (det != 0)
					{
						cout << "\nInverse is :\n";
						for (int i = 0; i < 3; i++) {
							for (int j = 0; j < 3; j++) {
								cout << inverse[i][j] << "\t";
							} cout << endl;
						} cout << endl;

						//multiplying matrix1 with inverse matrix
						cout << "result of multiplications is:" << endl;
						for (int i = 0; i < m1; i++) {
							for (int j = 0; j < n2; j++) {
								result[i][j] = 0;
								for (int k = 0; k < n1; k++) {
									result[i][j] += matrix1[i][k] * inverse[k][j];
								} cout << result[i][j] << "\t";
							} cout << endl;
						} cout << endl;
						m4 = m1;
						n4 = n2;
					}
					else {
						cout << "\nINVERSE NOT POSSIBLE AS DETERMINANT IS EQUAL TO ZERO";
						return 0;
					}
				}
				else if (n1 == 2) {
					//to get the inverse of a 2D matrix
					matrix2adj22[0][0] = matrix2[1][1];
					matrix2adj22[0][1] = -matrix2[0][1];
					matrix2adj22[1][0] = -matrix2[1][0];
					matrix2adj22[1][1] = matrix2[0][0];

					long int det = matrix2adj22[0][0] * matrix2adj22[1][1] - matrix2adj22[0][1] * matrix2adj22[1][0];

					for (int i = 0; i < 2; i++) {                        //For storing adjoint in another 2-D Array
						for (int j = 0; j < 2; j++) {
							inverse[i][j] = matrix2adj22[i][j];
						}
					}
					for (int i = 0; i < 2; i++) {                       //For calculating inverse of matrix (2-D Array)
						for (int j = 0; j < 2; j++) {
							inverse[i][j] = inverse[i][j] / det;
						}
					}
					if (det != 0)
					{
						cout << "\nInverse of the second matrix is :\n";
						for (int i = 0; i < 2; i++) {
							for (int j = 0; j < 2; j++) {
								cout << inverse[i][j] << "\t" << flush;
							} cout << endl;
						}

						//multiplying result with inverse of the new matrix
						cout << "result of multiplying matrix1 with inverse of matrix2 is:" << endl;
						for (int i = 0; i < m1; i++) {
							for (int j = 0; j < n2; j++) {
								result[i][j] = 0;
								for (int k = 0; k < n1; k++) {
									result[i][j] += matrix1[i][k] * inverse[k][j];
								} cout << result[i][j] << "\t";
							} cout << endl;
						} cout << endl;
						m4 = m1;
						n4 = n2;
					}
					else
						cout << "\nINVERSE NOT POSSIBLE AS DETERMINANT IS EQUAL TO ZERO";
				}
				else {
					cout << "the matrix by which you divide must be a 2*2 or a 3*3 matrix";
					return 0;
				}
			}
			else {
				cout << "Oops.. number of new matrix columns must be equal to number of previous result rows" << endl;
				return 0;
			}
			break;
		case 6:
			cout << "for matrix1 enter '1' for matrix2 enter '2' : " << flush;
			int select;
			cin >> select;
			cout << endl;
			if (select == 1) {
				for (i = 0; i < n1; i++) {
					for (int j = 0; j < m1; j++) {
						result[i][j] = matrix1[j][i];
						cout << result[i][j] << "\t";
					} cout << endl;
				} cout << endl;
				m4 = n1;
				n4 = m1;
			}
			else if (select == 2) {
				for (i = 0; i < n2; i++) {
					for (int j = 0; j < m2; j++) {
						result[i][j] = matrix2[j][i];
						cout << result[i][j] << "\t";
					} cout << endl;
				} cout << endl;
				m4 = n2;
				n4 = m2;
			}
			else {
				cout << "Oops.. not an option" << endl;
				return 0;
			} cout << endl;
			break;
		}
	} while (selection == 1);

	cout << "any more operations on the result y/n ? " << flush;
	string input;
	cin >> input;
	if (input == "y") {
		do {
			cout << endl << "enter numebr of new matrix's rows: " << flush;
			cin >> m3;
			cout << "enter number of new matrix's columns: " << flush;
			cin >> n3;
			cout << "enter your matrix: " << flush;
			cin >> matrixName >> symb >> symb;
			for (int i = 0; i < m3; i++) {
				for (int j = 0; j < n3; j++) {
					cin >> var[j + i * n3];
				} cin >> symb;
			}

			//any 1D array to 2D array
			for (int i = 0; i < m3; i++) {
				for (int j = 0; j < n3; j++) {
					variable[i][j] = var[j];
					var[j] = var[j + (i + 1) * n3];
				}
			}
			cout << endl << "matrix entered successfully.." << endl << endl;

			showMenu();
			cout << endl << "number of your choice is: " << flush;
			int selection, i = 0;
			cin >> selection;
			switch (selection) {
			default:
				cout << "please select from the menu.." << endl;
				cout << endl << "number of your choice is: " << flush;
				cin >> selection;
			case 1:
				cout << "for previous result enter '1' for the new matrix enter '2' : " << flush;
				int choice;
				cin >> choice;
				if (choice == 1) {
					for (int i = 0; i < m4; i++) {
						for (int j = 0; j < n4; j++) {
							cout << result[i][j] << "	";
						} cout << endl;
					} cout << endl;
				}
				else if (choice == 2) {
					for (int i = 0; i < m3; i++) {
						for (int j = 0; j < n3; j++) {
							cout << variable[i][j] << "	";
						} cout << endl;
					} cout << endl;
				}
				else {
					cout << "not valid.." << endl;
				}
			case 2:
				if (m4 == m3 && n4 == n3 && selection == 2) {
					cout << "The two matrices are added successfully...!!\n";
					cout << "The new matrix will be :\n";
					for (int i = 0; i < m3; i++) {
						for (int j = 0; j < n3; j++) {
							result[i][j] = result[i][j] + variable[i][j];
							cout << result[i][j] << " ";
						} cout << endl;
					}
					m4 = m3;
					n4 = n3;
				}
				else if (m4 != m3 || n4 != n3 && selection == 2) {
					cout << "Oops.. the two matrices must have the same dimensions" << endl;
				}
				break;
			case 3:
				if (m4 == m3 && n4 == n3 && selection == 3) {
					cout << "showing result for subtracting the new matrix from previous result: " << endl;
					for (int i = 0; i < m3; i++) {
						for (int j = 0; j < n3; j++) {
							result[i][j] = result[i][j] - variable[i][j];
							cout << result[i][j] << " ";
						} cout << endl;
					}
					m4 = m3;
					n4 = n3;
				}
				else if (m4 != m3 || n4 != n3 && selection == 3) {
					cout << "Oops.. the two matrices must have the same dimensions" << endl;
				}
				break;
			case 4:
				if (n4 == m3 && selection == 4) {
					for (int i = 0; i < m4; i++) {
						for (int j = 0; j < n3; j++) {
							result[i][j] = 0;
							for (int k = 0; k < n1; k++) {
								result[i][j] += result[i][k] * variable[k][j];
							} cout << result[i][j] << "\t";
						} cout << endl;
					} cout << endl;
					n4 = n3;
				}
				else {
					cout << "Oops.. number of new matrix columns must be equal to number of previous result rows" << endl;
				}
				break;
			case 5:
				//to get the inverse of a 2D matrix
				if (n4 == m3 && selection == 5) {
					if (m3 == 3) {
						variableadj[0][0] = variable[1][1] * variable[2][2] - variable[1][2] * variable[2][1];
						variableadj[0][1] = -1 * (variable[1][0] * variable[2][2] - variable[1][2] * variable[2][0]);
						variableadj[0][2] = variable[1][0] * variable[2][1] - variable[1][1] * variable[2][0];
						variableadj[1][0] = -1 * (variable[0][1] * variable[2][2] - variable[2][1] * variable[0][2]);
						variableadj[1][1] = variable[0][0] * variable[2][2] - variable[0][2] * variable[2][0];
						variableadj[1][2] = -1 * (variable[0][0] * variable[2][1] - variable[0][1] * variable[2][0]);
						variableadj[2][0] = variable[0][1] * variable[1][2] - variable[0][2] * variable[1][1];
						variableadj[2][1] = -1 * (variable[0][0] * variable[1][2] - variable[0][2] * variable[1][0]);
						variableadj[2][2] = variable[0][0] * variable[1][1] - variable[0][1] * variable[1][0];

						det = variable[0][0] * variableadj[0][0] + variable[0][1] * variableadj[0][1] + variable[0][2] * variableadj[0][2];

						for (int i = 0; i < 3; i++) {                        //For storing adjoint in another 2-D Array
							for (int j = 0; j < 3; j++)
								inverse[i][j] = variableadj[j][i];
						}
						for (int i = 0; i < 3; i++) {                       //For calculating inverse of matrix (2-D Array)
							for (int j = 0; j < 3; j++)
								inverse[i][j] = inverse[i][j] / det;
						}
						if (det != 0)
						{
							cout << "\nInverse of the second matrix is :\n";
							for (int i = 0; i < 3; i++) {
								for (int j = 0; j < 3; j++) {
									cout << inverse[i][j] << "\t";
								} cout << endl;
							} cout << endl;

							for (int i = 0; i < m4; i++) {
								for (int j = 0; j < n4; j++) {
									resultdiv[i][j] = result[i][j];
								}
							}

							//multiplying result with inverse of the new matrix
							cout << "result of multiplying matrix1 with inverse of matrix2 is:" << endl;
							for (int i = 0; i < m4; i++) {
								for (int j = 0; j < n3; j++) {
									result[i][j] = 0;
									for (int k = 0; k < n4; k++) {
										result[i][j] += resultdiv[i][k] * inverse[k][j];
									} cout << result[i][j] << "\t";
								} cout << endl;
							} cout << endl;
							n4 = n3;
						}
						else
							cout << "\nINVERSE NOT POSSIBLE AS DETERMINANT IS EQUAL TO ZERO";
					}
					else if (m3 == 2) {
						//to get the inverse of a 2D matrix
						matrix2adj22[0][0] = matrix2[1][1];
						matrix2adj22[0][1] = -matrix2[0][1];
						matrix2adj22[1][0] = -matrix2[1][0];
						matrix2adj22[1][1] = matrix2[0][0];

						long int det = matrix2adj22[0][0] * matrix2adj22[1][1] - matrix2adj22[0][1] * matrix2adj22[1][0];

						for (int i = 0; i < 2; i++) {                        //For storing adjoint in another 2-D Array
							for (int j = 0; j < 2; j++)
								inverse[i][j] = matrix2adj22[i][j];
						}
						for (int i = 0; i < 2; i++) {                       //For calculating inverse of matrix (2-D Array)
							for (int j = 0; j < 2; j++)
								inverse[i][j] = inverse[i][j] / det;
						}
						if (det != 0)
						{
							cout << "\nInverse of second matrix is :\n";
							for (int i = 0; i < 2; i++) {
								for (int j = 0; j < 2; j++) {
									cout << inverse[i][j] << "    ";
								} cout << endl;
							} cout << endl;
							for (int i = 0; i < m4; i++) {
								for (int j = 0; j < n4; j++) {
									resultdiv[i][j] = result[i][j];
								}
							}

							//multiplying result with inverse of the new matrix
							cout << "result of multiplying matrix1 with inverse of matrix2 is:" << endl;
							for (int i = 0; i < m4; i++) {
								for (int j = 0; j < n3; j++) {
									result[i][j] = 0;
									for (int k = 0; k < n4; k++) {
										result[i][j] += resultdiv[i][k] * inverse[k][j];
									} cout << result[i][j] << "\t";
								} cout << endl;
							} cout << endl;
							n4 = n3;
						}
						else
							cout << "\nINVERSE NOT POSSIBLE AS DETERMINANT( |A| ) IS EQUAL TO ZERO";
					}
				}
				else {
					cout << "Oops.. number of new matrix columns must be equal to number of previous result rows" << endl;
				}
				break;
			case 6:
				cout << "for previous result enter '1' for the new matrix enter '2' : " << flush;
				int select;
				cin >> select;
				cout << endl;
				if (select == 1) {
					for (i = 0; i < n4; i++) {
						for (int j = 0; j < m4; j++) {
							resultdiv[i][j] = result[j][i];
							cout << resultdiv[i][j] << "\t";
						} cout << endl;
					} cout << endl;
					m4 = n4;
					n4 = m4;
					for (i = 0; i < n4; i++) {
						for (int j = 0; j < m4; j++) {
							result[i][j] = resultdiv[i][j];
						}
					}
				}
				else if (select == 2) {
					for (i = 0; i < n3; i++) {
						for (int j = 0; j < m3; j++) {
							result[i][j] = variable[j][i];
							cout << result[i][j] << "\t";
						} cout << endl;
					} cout << endl;
					m4 = n3;
					m4 = m3;
				}
				else {
					cout << "Oops.. not an option" << endl;
				} cout << endl;
				break;
			}
			cout << "any more operations on the new result y/n ? " << flush;
			cin >> input;
		} while (input == "y");
		cout << endl << "\t\t\t\t\t\t\t GOODBYE !!" << endl;
	}
	else {
		cout << endl << "\t\t\t\t\t\t\t GOODBYE !!" << endl;
	}
}