typedef struct {
    char* id;
    int weight;
} package;

typedef struct {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
} post_office;

typedef struct {
    char* name;
    post_office* offices;
    int offices_count;
} town;

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office* src = &source->offices[source_office_index];
    post_office* tgt = &target->offices[target_office_index];

    package* src_packages = src->packages;
    int src_count = src->packages_count;

    package* accepted = malloc(src_count * sizeof(package));
    package* rejected = malloc(src_count * sizeof(package));
    int acc_count = 0, rej_count = 0;

    for (int i = 0; i < src_count; i++) {
        if (src_packages[i].weight >= tgt->min_weight && src_packages[i].weight <= tgt->max_weight) {
            accepted[acc_count++] = src_packages[i];
        } else {
            rejected[rej_count++] = src_packages[i];
        }
    }

    tgt->packages = realloc(tgt->packages, (tgt->packages_count + acc_count) * sizeof(package));
    for (int i = 0; i < acc_count; i++) {
        tgt->packages[tgt->packages_count++] = accepted[i];
    }

    free(src->packages);
    src->packages = malloc(rej_count * sizeof(package));
    for (int i = 0; i < rej_count; i++) {
        src->packages[i] = rejected[i];
    }
    src->packages_count = rej_count;

    free(accepted);
    free(rejected);
}

town town_with_most_packages(town* towns, int towns_count) {
    int max_count = -1;
    int max_index = 0;
    for (int i = 0; i < towns_count; i++) {
        int total = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            total += towns[i].offices[j].packages_count;
        }
        if (total > max_count) {
            max_count = total;
            max_index = i;
        }
    }
    return towns[max_index];
}

town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL; 
}