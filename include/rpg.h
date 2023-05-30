/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** my_rpg
*/

#include "import.h"

#pragma once

// RPG Structure
    typedef struct rpg {
        sfFont *font;
        bool is_active;
        struct my_clock clock;
        struct my_window window;
        struct background background;
        struct escape_menu menu;
        struct start_menu start;
        struct settings_menu settings;
        struct loader loader;
        struct fps fps;
        struct sprite sprite;
        struct view view;
        struct bar bar;
        struct safe_place safe_place;
        struct control_zone control_zone;
        struct factory factory;
        struct factory_basement factory_basement;
        struct logos_entrance logos_entrance;
        struct logos_office logos_office;
        struct logos_machine logos_machine;
        struct char_menu creator;
        struct fight_s fights;
        struct inventory_menu inventory;
        struct save save;
        sfSprite *knife_in_inventory;
        hud_t hud;
        tp_t tp;
        collectible_t collectible;
        mission_t mission;
        mission_text_t mission_text;
    } rpg_t;

    // Main Button
    enum ui_state {
        NONE,
        HOVER,
        PRESSED,
        RELEASED
    };
    struct button_color {
        sfColor color;
        sfColor hover_color;
        sfColor pressed_color;
    };
    struct button_info {
        sfVector2f pos;
        sfVector2f size;
    };
    struct my_button {
        struct button_color color;
        struct button_info info;
        sfRectangleShape *rect;
        sfBool (*is_clicked) (rpg_t *rpg, struct my_button *button,
            sfMouseButtonEvent *event);
        sfBool (*is_hover) (rpg_t *rpg, struct my_button *button,
            sfMouseMoveEvent *event);
        enum ui_state state;
    };


// Base function
    int main(void);
    void init_values(rpg_t *rpg);
    void background(rpg_t *rpg);
    void free_menu(rpg_t *rpg);
    void main_game_loop(rpg_t *rpg);
    void handle_scene(rpg_t *rpg);
    void mission_scene(rpg_t *rpg);

        // Player function
        void init_view(rpg_t *rpg);
        void init_sprite(rpg_t *rpg);
        void animation(rpg_t *rpg);
        void scrolling(rpg_t *rpg);
        void stop_move(rpg_t *rpg);
        void move_player(rpg_t *rpg);
        void position(rpg_t *rpg);

// Map function
    void display_map(rpg_t *rpg);
    void init_map(rpg_t *rpg);

        // MiniMap Hud function
        int init_mini_map(rpg_t *rpg);
        void minimap(rpg_t *rpg);

// Bar function
        void init_bar_scene(rpg_t *rpg);
        void display_bar_scene(rpg_t *rpg);
        void init_tp_player(rpg_t *rpg, float x, float y);
        void wall_bar_collision(rpg_t *rpg, sfImage *image);

// Menu function
        // Escape menu main button
        sfBool is_clicked(rpg_t *rpg, struct my_button *button,
            sfMouseButtonEvent *event);
        sfBool is_hovered(rpg_t *rpg, struct my_button *button,
            sfMouseMoveEvent *event);

// Escape Menu Init & Display
        void init_escape_menu_values(rpg_t *rpg);
        void display_escape_menu(rpg_t *rpg);

        // Escape Menu Button Init
        void init_escape_credit(rpg_t *rpg);
        void init_escape_load(rpg_t *rpg);
        void init_escape_quit(rpg_t *rpg);
        void init_escape_resume(rpg_t *rpg);
        void init_escape_settings(rpg_t *rpg);

        // Escape Menu Button Display
        void escape_credits_view(rpg_t *rpg);
        void escape_load_view(rpg_t *rpg);
        void escape_quit_view(rpg_t *rpg);
        void escape_resume_view(rpg_t *rpg);
        void escape_settings_view(rpg_t *rpg);

        // Escape Menu Button Event
        void escape_button_event(rpg_t *rpg);
        void escape_credits_event(rpg_t *rpg);
        void escape_quit_event(rpg_t *rpg);
        void escape_load_event(rpg_t *rpg);
        void escape_resume_event(rpg_t *rpg);
        void escape_settings_event(rpg_t *rpg);

// Start menu main button
        //  Start Menu Init & Display
        void init_start_menu_values(rpg_t *rpg);
        void display_start_menu(rpg_t *rpg);

        //  Start Menu Button Init
        void init_start_credit(rpg_t *rpg);
        void init_start_load(rpg_t *rpg);
        void init_start_quit(rpg_t *rpg);
        void init_start_new(rpg_t *rpg);
        void init_start_settings(rpg_t *rpg);

        //  Start Menu Button Display
        void start_credits_view(rpg_t *rpg);
        void start_load_view(rpg_t *rpg);
        void start_quit_view(rpg_t *rpg);
        void start_new_view(rpg_t *rpg);
        void start_settings_view(rpg_t *rpg);

        //  Start Menu Button Event
        void start_button_event(rpg_t *rpg);
        void start_credits_event(rpg_t *rpg);
        void start_quit_event(rpg_t *rpg);
        void start_load_event(rpg_t *rpg);
        void start_new_event(rpg_t *rpg);
        void start_settings_event(rpg_t *rpg);

        //  Start Menu Button How to play
        void start_init_how_to_play_bg(rpg_t *rpg);
        void start_how_to_play_view(rpg_t *rpg);
        void start_how_to_play_event(rpg_t *rpg);

// Loader
        // Loader Init & Display
        void display_loader(rpg_t *rpg);
        void init_loader_values(rpg_t *rpg);

        // Loader Image Init
        void init_loader_image(rpg_t *rpg);

        // Loader Image Display
        void display_loader(rpg_t *rpg);
        void loader_image_open(rpg_t *rpg);
        void loader_first_image_open(rpg_t *rpg);

        // Loader Rect Init & Display
        void init_loader_fade_rect(rpg_t *rpg);
        void init_loader_load(rpg_t *rpg);
        void display_loader_load(rpg_t *rpg);

// Settings
    void init_settings_values(rpg_t *rpg);
    void display_settings(rpg_t *rpg);

        // Settings Events
        void close_settings_menu(rpg_t *rpg);

        // Settings Button
        void init_fps_number(rpg_t *rpg);
        void fps_number_view(rpg_t *rpg);

        // Settings Button Init
        void init_add_fps(rpg_t *rpg);
        void init_remove_fps(rpg_t *rpg);
        void init_middle_button(rpg_t *rpg);
        void init_normal_button(rpg_t *rpg);
        void init_small_button(rpg_t *rpg);
        void init_choose_button(rpg_t *rpg);
        void init_hdr_number(rpg_t *rpg);
        void init_sound_settings(rpg_t *rpg);
        void init_sfx_on_button(rpg_t *rpg);
        void init_sfx_off_button(rpg_t *rpg);
        void init_music_on_button(rpg_t *rpg);
        void init_music_off_button(rpg_t *rpg);
        void init_interaction_key_button(rpg_t *rpg);

        // Settings Button View
        void add_fps_view(rpg_t *rpg);
        void remove_fps_view(rpg_t *rpg);
        void middle_button_view(rpg_t *rpg);
        void normal_button_view(rpg_t *rpg);
        void small_button_view(rpg_t *rpg);
        void choose_button_view(rpg_t *rpg);

        void hdr_number_view(rpg_t *rpg);
        void display_sound_settings(rpg_t *rpg);
        void sfx_on_button_view(rpg_t *rpg);
        void sfx_off_button_view(rpg_t *rpg);
        void music_on_button_view(rpg_t *rpg);
        void music_off_button_view(rpg_t *rpg);
        void interaction_key_button_view(rpg_t *rpg);

        // Settings Button Event
        void add_fps_event(rpg_t *rpg);
        void remove_fps_event(rpg_t *rpg);
        void small_screen_event(rpg_t *rpg);
        void middle_screen_event(rpg_t *rpg);
        void normal_screen_event(rpg_t *rpg);
        void choose_screen_event(rpg_t *rpg);

        void sfx_on_button_event(rpg_t *rpg);
        void sfx_off_button_event(rpg_t *rpg);
        void music_on_button_event(rpg_t *rpg);
        void music_off_button_event(rpg_t *rpg);
        void interaction_key_button_event(rpg_t *rpg);
        void ceo_screen_size(rpg_t *rpg);
        void which_size_button_event(rpg_t *rpg);

// Inventory
    void inventory_event(rpg_t *rpg);
    void display_inventory(rpg_t *rpg);
    void init_inventory_values(rpg_t *rpg);

        // Inventory Title init & display
        void init_inventory_title(rpg_t *rpg);
        void display_inventory_title(rpg_t *rpg);
        void init_inventory_background(rpg_t *rpg);

        // Inventory Button (rect)
        void first_inventory_event(rpg_t *rpg);
        void first_inventory_view(rpg_t *rpg);
        void first_inventory_init(rpg_t *rpg);
        void second_inventory_event(rpg_t *rpg);
        void second_inventory_view(rpg_t *rpg);
        void second_inventory_init(rpg_t *rpg);
        void third_inventory_event(rpg_t *rpg);
        void third_inventory_view(rpg_t *rpg);
        void third_inventory_init(rpg_t *rpg);
        void fourth_inventory_event(rpg_t *rpg);
        void fourth_inventory_view(rpg_t *rpg);
        void fourth_inventory_init(rpg_t *rpg);
        void fifth_inventory_event(rpg_t *rpg);
        void fifth_inventory_view(rpg_t *rpg);
        void fifth_inventory_init(rpg_t *rpg);
        void six_inventory_event(rpg_t *rpg);
        void six_inventory_view(rpg_t *rpg);
        void six_inventory_init(rpg_t *rpg);

// Char creator
    void display_char_menu(rpg_t *rpg);
    void init_char_values(rpg_t *rpg);

        // Init Player Clothes
        void right_player_view(rpg_t *rpg);
        void init_right_player(rpg_t *rpg);
        void right_player_event(rpg_t *rpg);
        void left_player_view(rpg_t *rpg);
        void init_left_player(rpg_t *rpg);
        void left_player_event(rpg_t *rpg);

        // Char creator Event
        void char_creator_event(rpg_t *rpg);

        // Player choice
        void choice_sprite_view(rpg_t *rpg);
        void init_choice_sprite(rpg_t *rpg);
        void init_second_choice_sprite(rpg_t *rpg);

        // Skills Button
        void display_speed_button(rpg_t *rpg);
        void speed_creator_button(rpg_t *rpg);
        void speed_creator_event(rpg_t *rpg);
        void strength_creator_button(rpg_t *rpg);
        void display_strength_button(rpg_t *rpg);
        void strength_creator_event(rpg_t *rpg);
        void intelligence_creator_button(rpg_t *rpg);
        void display_intelligence_button(rpg_t *rpg);
        void intelligence_creator_event(rpg_t *rpg);

        // Start Game Button
        void init_start_game_creator(rpg_t *rpg);
        void start_game_creator_view(rpg_t *rpg);
        void start_game_creator_event(rpg_t *rpg);
        void init_start_game_creator_hover(rpg_t *rpg);
        void init_start_game_creator_txt(rpg_t *rpg);
        void init_start_how_to_play_img(rpg_t *rpg);

// Map
        // Init
        int init_three_d_map(rpg_t *rpg);
        void init_control_zone_scene(rpg_t *rpg);
        void init_factory_basement_scene(rpg_t *rpg);
        void init_factory_scene(rpg_t *rpg);
        void init_logos_entrance_scene(rpg_t *rpg);
        void init_logos_machine_scene(rpg_t *rpg);
        void init_logos_office_scene(rpg_t *rpg);
        void init_safe_place_scene(rpg_t *rpg);
        // Display
        void display_factory_scene(rpg_t *rpg);
        void display_factory_basement_scene(rpg_t *rpg);
        void display_safe_place_scene(rpg_t *rpg);
        void display_logos_machine_scene(rpg_t *rpg);
        void display_logos_office_scene(rpg_t *rpg);
        void display_logos_entrance_scene(rpg_t *rpg);
        void display_control_zone_scene(rpg_t *rpg);
        void display_render_texture(rpg_t *rpg);
        // wall detection
        void wall_factory_collision(rpg_t *rpg, sfImage *image);
        void wall_factory_basement_collision(rpg_t *rpg, sfImage *image);
        void wall_logos_machine_collision(rpg_t *rpg, sfImage *image);
        void wall_logos_office_collision(rpg_t *rpg, sfImage *image);
        void wall_logos_entrance_collision(rpg_t *rpg, sfImage *image);
        void wall_control_zone_collision(rpg_t *rpg, sfImage *image);
        void wall_safe_place_collision(rpg_t *rpg, sfImage *image);
        void wall_map_collision(rpg_t *rpg, sfImage *image);
        void three_d_map_collision(rpg_t *rpg, sfImage *image,
            bool *is_moving);
        //Tool
        bool is_same_color(sfColor color, sfColor targeted_color);
        bool map_collectible_collision(rpg_t *rpg, sfRectangleShape *rect);
        bool collectible_collision(rpg_t *rpg, sfRectangleShape *rect);

// Collectibles
        // Init
        int init_collectibles(rpg_t *rpg);
        int init_knife(rpg_t *rpg);
        int init_main_place_npc(rpg_t *rpg);
        void init_knife_inventory(rpg_t *rpg);
        // Manage
        void manage_map_collectibles(rpg_t *rpg);
        void manage_main_place_npc(rpg_t *rpg);
        // Texts
        char *load_message_content_map_place(void);
        void load_map_place_message(rpg_t *rpg);

// NPC
        // Init
        int init_bar_npc(rpg_t *rpg);
        void load_safe_place_message(rpg_t *rpg);
        void load_bar_message(rpg_t *rpg);
        void load_control_zone_message(rpg_t *rpg);
        int init_safe_place_npc(rpg_t *rpg);
        int init_control_zone_npc(rpg_t *rpg);
        int init_back_safe_place_npc(rpg_t *rpg);
        void load_back_safe_place_message(rpg_t *rpg);
        void init_back_safe_place_mate_npc(rpg_t *rpg);
        // Draw
        bool draw_text_npc(rpg_t *rpg, char *message_content, sfText *message,
            unsigned int *letter_counter);
        void manage_bar_npc(rpg_t *rpg);
        void manage_safe_place_npc(rpg_t *rpg);
        void manage_back_safe_place_npc(rpg_t *rpg);

        // Change
        void change_e_interaction_texture(rpg_t *rpg, sfSprite *e_interaction,
            bool get, bool last);
        void manage_control_zone_npc(rpg_t *rpg);

// TP
        // Change scene
        void change_other_scene(rpg_t *rpg);
        void change_scene(rpg_t *rpg);
        void change_single_scene(rpg_t *rpg);
        void change_logos_intern_scene(rpg_t *rpg);
        void change_factory_scene(rpg_t *rpg);
        void display_game_collectibles(rpg_t *rpg);
        int init_font(rpg_t *rpg);

// Fight
        // Init
        void init_fights(struct fight_s *fights);
        void init_choices(struct fight_s *fights);
        void init_player(struct fight_s *fights);
        void init_place(struct fight_s *fights);
        void init_control(struct fight_s *fights);
        void init_cofirsts(struct fight_s *fights);
        void init_coattacks(struct fight_s *fights);
        void init_coinventories(struct fight_s *fights);
        void init_coenemy(struct fight_s *fights);
        void init_coenemy_turn(struct fight_s *fights);
        void init_plfirsts(struct fight_s *fights);
        void init_plattacks(struct fight_s *fights);
        void init_plinventories(struct fight_s *fights);
        void init_plenemies(struct fight_s *fights);
        void init_plenemies_turn(struct fight_s *fights);
        void init_menues_values(rpg_t *rpg);
        void init_scenes_values(rpg_t *rpg);
        void init_place_hud(struct fight_s *fights);
        void init_control_hud(struct fight_s *fights);
            void player_life(struct fight_s *fights, sfColor color);
            void player_speed(struct fight_s *fights, sfColor color);
            void player_mind(struct fight_s *fights, sfColor color);
            void player_lvl(struct fight_s *fights, sfColor color);
            void enemies_life(struct fight_s *fights, sfColor color);
            void enemies_lvl(struct fight_s *fights, sfColor color);
            void boss_life(struct fight_s *fights, sfColor color);
            void boss_mind(struct fight_s *fights, sfColor color);
            void boss_lvl(struct fight_s *fights, sfColor color);

        // Display
        void fightscene(rpg_t *rpg, struct fight_s *fights);
        void place_scene(rpg_t *rpg, struct fight_s *fights);
        void control_scene(rpg_t *rpg, struct fight_s *fights);
        void display_fight_hud(rpg_t *rpg, struct fight_s *fights);
        void check_player_datas(struct fight_s *fights, int idx);
        void check_enemies_datas(struct fight_s *fights, int idx);
        void plcheck_life(struct fight_s *fights, int idx);
        void plcheck_mind(struct fight_s *fights, int idx);
        void plcheck_speed(struct fight_s *fights, int idx);
        void cocheck_life(struct fight_s *fights, int idx);
        void cocheck_mind(struct fight_s *fights, int idx);
        void check_boss_datas(struct fight_s *fights);
            // Subfuncs
                void replace_plstr(struct fight_s *fights,
                    int tmp, int idx, char *str);
                void replace_costr(struct fight_s *fights,
                    int tmp, int idx, char *str);
                void replace_pltexture(struct fight_s *fights,
                    int idx, char *path);
                void replace_cotexture(struct fight_s *fights,
                    int idx, char *path);

        // Events
        void handle_choice(struct fight_s *fights);
        void handle_bosschoice(struct fight_s *fights);
        void fight_process(rpg_t *rpg, struct fight_s *fights);
        void enemies_event(struct fight_s *fights);
        void place_enemies_event(struct fight_s *fights);
        void control_boss_event(struct fight_s *fights);

        // Animation
        void player_animation(struct fight_s *fights);
        void enemies_animation(struct fight_s *fights, unsigned int i);
        void boss_animation(struct fight_s *fights);

        // Choices
        void first_choice(struct fight_s *fights);
        void attack_choice(struct fight_s *fights);
        void inventory_choice(struct fight_s *fights);
        void enemy_choice(struct fight_s *fights);
            void change_from_first2(struct fight_s *fights);
            void change_from_mid2(struct fight_s *fights);
            void change_from_back(struct fight_s *fights, int tmp);
        void first_bosschoice(struct fight_s *fights);
        void attack_bosschoice(struct fight_s *fights);
        void inventory_bosschoice(struct fight_s *fights);
        void enemy_bosschoice(struct fight_s *fights);

        // Validation
        void validation_ceo(struct fight_s *fights);
        void first_validation(struct fight_s *fights);
        void attack_validation(struct fight_s *fights);
        void inventory_validation(struct fight_s *fights);
        void enemy_validation(struct fight_s *fights);
        void first_boss_vld(struct fight_s *fights);
        void attack_boss_vld(struct fight_s *fights);
        void inventory_boss_vld(struct fight_s *fights);
        void boss_validation(struct fight_s *fights);

        // Back
        void attack_back(struct fight_s *fights);
        void inventory_back(struct fight_s *fights);
        void enemy_back(struct fight_s *fights);
        void display_fight_background(rpg_t *rpg);
        void init_fight_background(rpg_t *rpg);
        void attack_bossback(struct fight_s *fights);
        void boss_back(struct fight_s *fights);
        void inventory_bossback(struct fight_s *fights);
        void handle_fight(rpg_t *rpg);

        // Others
        void upd8_player_datas(struct fight_s *fights);

// Save
        void enter_text_event(rpg_t *rpg);
        void enter_text_text(rpg_t *rpg);
        void display_save_txt(rpg_t *rpg);
        void init_save_values(rpg_t *rpg);
        void enter_text(rpg_t *rpg);
        void display_save_background(rpg_t *rpg);
        void init_save_background(rpg_t *rpg);
        void display_save_menu(rpg_t *rpg);
        void init_save_button(rpg_t *rpg);
        void save_button_view(rpg_t *rpg);
        void save_button_event(rpg_t *rpg);
        void open_button_view(rpg_t *rpg);
        void init_open_button(rpg_t *rpg);
        void open_button_event(rpg_t *rpg);
        void save_ceo_event(rpg_t *rpg);

    // Missions
        // Init
        void init_mission(rpg_t *rpg);
        // Text:
        void display_bar_mission_text(rpg_t *rpg);
        void display_back_safe_place_mission_text(rpg_t *rpg);
        void display_knife_mission_text(rpg_t *rpg);
        void display_main_place_mission_text(rpg_t *rpg);
        void display_find_safe_place_mission_text(rpg_t *rpg);
        void display_control_zone_mission_text(rpg_t *rpg);
        void display_do_fight_mission_text(rpg_t *rpg);
        // Tool
        bool draw_mission_text(rpg_t *rpg,
            char *message_content, sfText *message,
                unsigned int *letter_counter);
        bool map_collectible_collision(rpg_t *rpg, sfRectangleShape *rect);

        void display_hud_background_menu(rpg_t *rpg);
        void init_hud_background_menu(rpg_t *rpg);
        void display_draw_text_hud(rpg_t *rpg);
        void init_draw_text_hud(rpg_t *rpg);

    // destroy
        void destroy_missions(rpg_t *rpg);
        void destroy_collectibles(rpg_t *rpg);
        void destroy_font(rpg_t *rpg);
        void destroy_npc(rpg_t *rpg);

    void map_tp_control_zone(rpg_t *rpg, sfColor color);
    void map_tp(rpg_t *rpg, sfColor color);
    void valid_boss_fight(rpg_t *rpg);
    void reset_simple_room(rpg_t *rpg);
    void do_main_place_fight(rpg_t *rpg);
    void init_advancement(rpg_t *rpg);
