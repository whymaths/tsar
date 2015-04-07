#include "tsar.h"

static char *summary = "test2_summary";

static char *get_data()
{
	char data[64] = {0};
	
	sprintf(data, "test210%s11", DATA_SPLIT);

	return strdup(data);
}


static void func_data_collect(struct module *mod, int data_type)
{
	mod->detail = get_data();
	mod->summary = get_data();
}


static void func_mod_free(struct module *mod)
{
	free(mod->detail);
	free(mod->summary);
	mod->detail = NULL;
	mod->summary = NULL;
}


static char *get_summary_by_detail(char *detail)
{
	return summary;
}


void mod_register(struct module *mod)
{
	sprintf(mod->detail_hdr, "test2_Mem%sCpu", DATA_SPLIT);
	sprintf(mod->summary_hdr, "test2_summary");
	sprintf(mod->opt_line, "--test2");
	mod->get_summary_by_detail = get_summary_by_detail;
	mod->data_collect = func_data_collect;
	mod->mod_free = func_mod_free;
}
