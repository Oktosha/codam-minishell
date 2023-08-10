#include <assert.h>
#include <string.h>
#include "execute.h"

void ex_test_dirs(char *title, char *path, char **expected, int expected_n)
{
	printf("%s test for l_ex_extract_dir_candidates\n", title);
	printf("%s\n", path);
	char **dirs = l_ex_extract_dir_candidates(path);
	int n_dirs = l_ex_n_records_before_null(dirs);
	assert(expected_n == n_dirs);
	for (int i = 0; i < n_dirs; ++i)
	{
		printf("[%d] \"%s\" (expected \"%s\")\n", i, dirs[i], expected[i]);
		assert(strcmp(expected[i], dirs[i]) == 0);
	}
	l_ex_free_array(dirs, n_dirs);
	printf("\n\n");
}

void ex_all_tests_for_l_ex_extract_dir_candidates(void)
{
	char *normal_path = "/urs/bin:/usr/local/bin:/opt/homebrew/bin";
	char *normal_expected[3] = {"/urs/bin/", "/usr/local/bin/", "/opt/homebrew/bin/"};
	ex_test_dirs("Normal path", normal_path, normal_expected, 3);

	char *empty_path = "";
	char *empty_expected[1] = {""};
	ex_test_dirs("Empty path", empty_path, empty_expected, 1);

	char *space_path = " ";
	char *space_expected[1] = {" /"};
	ex_test_dirs("Space path", space_path, space_expected, 1);

	char *path_with_leading_colon = ":/usr/bin:/usr/local/bin";
	char *leading_colon_expected[3] = {"", "/usr/bin/", "/usr/local/bin/"};
	ex_test_dirs("Leading colon", path_with_leading_colon, leading_colon_expected, 3);

	char *path_with_trailing_colon = "/usr/bin:/usr/local/bin:";
	char *trailing_colon_expected[3] = {"/usr/bin/", "/usr/local/bin/", ""};
	ex_test_dirs("Trailing colon", path_with_trailing_colon, trailing_colon_expected, 3);

	char *path_with_two_colons_in_middle = "/usr/bin::/usr/local/bin";
	char *two_colons_expected[3] = {"/usr/bin/", "", "/usr/local/bin/"};
	ex_test_dirs("Two colons", path_with_two_colons_in_middle, two_colons_expected, 3);

	char *path_with_lots_of_colons = ":::";
	char *lots_of_colons_expected[4] = {"", "", "", ""};
	ex_test_dirs("Many colons", path_with_lots_of_colons, lots_of_colons_expected, 4);
}

void ex_all_tests_for_l_ex_get_cmd_candidates(void)
{
	char **cmds = l_ex_get_cmd_candidates("cmd", "a:/b/c:");
	char *expected[3] = {"a/cmd", "/b/c/cmd", "cmd"};
	assert(l_ex_n_records_before_null(cmds) == 3);
	for (int i = 0; i < 3; ++i)
	{
		assert(strcmp(cmds[i], expected[i]) == 0);
	}
	l_ex_free_array(cmds, 3);
	char **dircmd = l_ex_get_cmd_candidates("./cmd", "a:/b/c:");
	assert(l_ex_n_records_before_null(dircmd) == 1);
	assert(strcmp(dircmd[0], "./cmd") == 0);
	l_ex_free_array(dircmd, 1);
}

int main()
{
	ex_all_tests_for_l_ex_extract_dir_candidates();
	ex_all_tests_for_l_ex_get_cmd_candidates();
	return 0;
}
