/* Smoketest the install instructions posted at:
 * https://github.com/GENIVI/dlt-daemon/blob/master/INSTALL
 *
 * A corrected version of the DLT - Hello world example listed in:
 * https://raw.githubusercontent.com/GENIVI/dlt-daemon/master/doc/dlt_user_manual.txt
 *
 * Make with: gcc dltdemo.c -o dltdemo -ldlt
 *
 * Test with:
 *   touch /tmp/dlt
 *   ./dltdemo
 *   xxd -c 34 /tmp/dlt
 *
 * Correction detailed at:
 * https://lists.genivi.org/pipermail/genivi-diagnostic-log-and-trace/2017-May/000500.html
 *
 */

#include <stdio.h>
#include <dlt/dlt.h>
DLT_DECLARE_CONTEXT(mycontext);
int main(int argc, char *argv[])
{
	int num;

	DLT_REGISTER_APP("MYAP", "My Application");
	DLT_REGISTER_CONTEXT(mycontext, "MYCT", "My Context");

	printf("Hello world");

	for (num = 0; num < 10; num++) {
		DLT_LOG(mycontext,
			DLT_LOG_INFO,
			DLT_STRING("Hello world"),
			DLT_INT(num));
		sleep(1);
	}

	DLT_UNREGISTER_CONTEXT(mycontext);
	DLT_UNREGISTER_APP();
	return 0;
}
