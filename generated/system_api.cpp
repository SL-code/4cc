function void
system_api_fill_vtable(API_VTable_system *vtable){
vtable->get_path = system_get_path;
vtable->get_canonical = system_get_canonical;
vtable->get_file_list = system_get_file_list;
vtable->quick_file_attributes = system_quick_file_attributes;
vtable->load_handle = system_load_handle;
vtable->load_attributes = system_load_attributes;
vtable->load_file = system_load_file;
vtable->load_close = system_load_close;
vtable->save_file = system_save_file;
vtable->load_library = system_load_library;
vtable->release_library = system_release_library;
vtable->get_proc = system_get_proc;
vtable->now_time = system_now_time;
vtable->wake_up_timer_create = system_wake_up_timer_create;
vtable->wake_up_timer_release = system_wake_up_timer_release;
vtable->wake_up_timer_set = system_wake_up_timer_set;
vtable->signal_step = system_signal_step;
vtable->sleep = system_sleep;
vtable->post_clipboard = system_post_clipboard;
vtable->cli_call = system_cli_call;
vtable->cli_begin_update = system_cli_begin_update;
vtable->cli_update_step = system_cli_update_step;
vtable->cli_end_update = system_cli_end_update;
vtable->open_color_picker = system_open_color_picker;
vtable->get_screen_scale_factor = system_get_screen_scale_factor;
vtable->thread_launch = system_thread_launch;
vtable->thread_join = system_thread_join;
vtable->thread_free = system_thread_free;
vtable->thread_get_id = system_thread_get_id;
vtable->mutex_make = system_mutex_make;
vtable->mutex_acquire = system_mutex_acquire;
vtable->mutex_release = system_mutex_release;
vtable->mutex_free = system_mutex_free;
vtable->condition_variable_make = system_condition_variable_make;
vtable->condition_variable_wait = system_condition_variable_wait;
vtable->condition_variable_signal = system_condition_variable_signal;
vtable->condition_variable_free = system_condition_variable_free;
vtable->memory_allocate = system_memory_allocate;
vtable->memory_set_protection = system_memory_set_protection;
vtable->memory_free = system_memory_free;
vtable->show_mouse_cursor = system_show_mouse_cursor;
vtable->set_fullscreen = system_set_fullscreen;
vtable->is_fullscreen = system_is_fullscreen;
}
#if defined(DYNAMIC_LINK_API)
function void
system_api_read_vtable(API_VTable_system *vtable){
system_get_path = vtable->get_path;
system_get_canonical = vtable->get_canonical;
system_get_file_list = vtable->get_file_list;
system_quick_file_attributes = vtable->quick_file_attributes;
system_load_handle = vtable->load_handle;
system_load_attributes = vtable->load_attributes;
system_load_file = vtable->load_file;
system_load_close = vtable->load_close;
system_save_file = vtable->save_file;
system_load_library = vtable->load_library;
system_release_library = vtable->release_library;
system_get_proc = vtable->get_proc;
system_now_time = vtable->now_time;
system_wake_up_timer_create = vtable->wake_up_timer_create;
system_wake_up_timer_release = vtable->wake_up_timer_release;
system_wake_up_timer_set = vtable->wake_up_timer_set;
system_signal_step = vtable->signal_step;
system_sleep = vtable->sleep;
system_post_clipboard = vtable->post_clipboard;
system_cli_call = vtable->cli_call;
system_cli_begin_update = vtable->cli_begin_update;
system_cli_update_step = vtable->cli_update_step;
system_cli_end_update = vtable->cli_end_update;
system_open_color_picker = vtable->open_color_picker;
system_get_screen_scale_factor = vtable->get_screen_scale_factor;
system_thread_launch = vtable->thread_launch;
system_thread_join = vtable->thread_join;
system_thread_free = vtable->thread_free;
system_thread_get_id = vtable->thread_get_id;
system_mutex_make = vtable->mutex_make;
system_mutex_acquire = vtable->mutex_acquire;
system_mutex_release = vtable->mutex_release;
system_mutex_free = vtable->mutex_free;
system_condition_variable_make = vtable->condition_variable_make;
system_condition_variable_wait = vtable->condition_variable_wait;
system_condition_variable_signal = vtable->condition_variable_signal;
system_condition_variable_free = vtable->condition_variable_free;
system_memory_allocate = vtable->memory_allocate;
system_memory_set_protection = vtable->memory_set_protection;
system_memory_free = vtable->memory_free;
system_show_mouse_cursor = vtable->show_mouse_cursor;
system_set_fullscreen = vtable->set_fullscreen;
system_is_fullscreen = vtable->is_fullscreen;
}
#undef DYNAMIC_LINK_API
#endif