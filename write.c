#include "write.h"

void writeBeautiful(t_tag* list, FILE * result) {

    t_properties* tmp_prop = NULL;
    t_tag* tmp_tag = list;

    while(tmp_tag != NULL)
    {
        fputs(tmp_tag->name, result);
        fputs(" {\n", result);

        tmp_prop = tmp_tag->props;
        while(tmp_prop != NULL)
        {
            fputs("\t", result);
            fputs(tmp_prop->prop, result);
            fputs(":", result);
            fputs(tmp_prop->value, result);
            fputs(";\n", result);

            tmp_prop = tmp_prop->next;
        }

        fputs("}\n", result);

        tmp_tag = tmp_tag->next;
    }
}

void writeMinimized(t_tag* list, FILE * result) {
    t_properties* tmp_prop = NULL;
    t_tag* tmp_tag = list;

    while(tmp_tag != NULL)
    {
        fputs(tmp_tag->name, result);
        fputs("{", result);

        tmp_prop = tmp_tag->props;
        while(tmp_prop != NULL)
        {
            fputs(tmp_prop->prop, result);
            fputs(":", result);
            fputs(tmp_prop->value, result);
            fputs(";", result);

            tmp_prop = tmp_prop->next;
        }

        fputs("}", result);

        tmp_tag = tmp_tag->next;
    }
}
