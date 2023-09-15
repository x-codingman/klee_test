#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

int main()
{
    TX_EVENT_FLAGS_GROUP * group_ptr;
    klee_make_symbolic_controllable(&group_ptr, sizeof(group_ptr), "group_ptr", true);
    VOID (*events_set_notify)(TX_EVENT_FLAGS_GROUP *notify_group_ptr);
    klee_make_symbolic_controllable(&events_set_notify, sizeof(events_set_notify), "events_set_notify", true);
    mevent_flags_set_notify(group_ptr, events_set_notify);
}
