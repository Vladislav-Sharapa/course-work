#pragma once

struct student {
	char studentName[30] = { '\0' };
	short int socialActivity = 0;
	char groupNumber[20] = { '\0' };
	double averageScore = 0;

	struct familyIncome {
		double firstIncome = 0;
		double secondIncome = 0;
		double netIncome = 0;
		bool flag = false;
	}income;
};

enum modeOfProgram { edit_mode = 1, processing_mode, close_program = 0 };
enum modeOfEditing { add_student_info = 1, delete_student_structer, edit_student_info, get_data_from_file, record_data_in_file, close_editing_menu = 0 };
enum modeOfProcessing { search_student_info = 1, sort_menu, individual_task, close_processing_mode = 0 };
enum modeOfSerching { search_by_name = 1, search_by_group, search_by_average_number, close_search_menu = 0 };
enum modeOfSorting { sort_by_name = 1, sort_by_average_mark, sort_by_income, close_sort_menu = 0 };
