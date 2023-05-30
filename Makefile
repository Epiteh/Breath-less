##
## EPITECH PROJECT, 2023
## read_html_file
## File description:
## Makefile
##

NAME 		=	 	my_rpg

SRC			=		./src/main.c										\
					./src/game/loop.c									\
					./src/game/scene/mission.c							\
					./src/game/background.c								\
					./src/game/scene/handle.c							\
					./src/game/scene/fight.c							\
					./src/game/scene/render_texture.c					\
					./src/free/free_menu.c								\
					./src/init/values.c									\
					./src/init/player.c									\
					./src/menu/button/ceo.c								\
					./src/loader/display/display.c						\
					./src/loader/init/values.c							\
					./src/loader/image/first.c							\
					./src/loader/image/other.c							\
					./src/loader/image/init.c							\
					./src/loader/image/fade.c							\
					./src/menu/start/button/new.c						\
					./src/menu/start/button/load.c						\
					./src/menu/start/button/settings.c					\
					./src/menu/start/button/credits.c					\
					./src/menu/start/button/quit.c						\
					./src/menu/start/init/values.c						\
					./src/menu/start/display/menu.c						\
					./src/menu/start/button/event/button.c				\
					./src/menu/start/button/event/ceo.c					\
					./src/menu/start/button/how_to_play.c				\
					./src/menu/escape/button/resume.c					\
					./src/menu/escape/button/load.c						\
					./src/menu/escape/button/settings.c					\
					./src/menu/escape/button/credits.c					\
					./src/menu/escape/button/quit.c						\
					./src/menu/escape/init/values.c						\
					./src/menu/escape/display/menu.c					\
					./src/menu/escape/button/event/button.c				\
					./src/menu/escape/button/event/ceo.c				\
					./src/player/animation.c							\
					./src/player/hitbox.c								\
					./src/player/position.c								\
					./src/player/scrolling.c							\
					./src/player/movement.c								\
					./src/hud/init/hud_map.c							\
					./src/hud/map/draw.c								\
					./src/hud/display.c									\
					./src/hud/txt/life.c								\
					./src/game/bar/bar.c								\
					./src/game/bar/collision.c							\
					./src/menu/settings/display/display.c				\
					./src/menu/settings/init/values.c					\
					./src/menu/settings/event/ceo.c						\
					./src/menu/settings/fps/number.c					\
					./src/menu/settings/fps/add.c						\
					./src/menu/settings/fps/remove.c					\
					./src/menu/settings/screen/button/normal.c			\
					./src/menu/settings/screen/button/middle.c			\
					./src/menu/settings/screen/button/small.c			\
					./src/menu/settings/screen/button/choose.c			\
					./src/menu/settings/screen/event/screen.c			\
					./src/menu/settings/hdr/txt.c						\
					./src/menu/settings/sound/init.c					\
					./src/menu/settings/sound/display.c					\
					./src/menu/settings/sound/sfx/button/on.c			\
					./src/menu/settings/sound/sfx/event/on.c			\
					./src/menu/settings/sound/sfx/button/off.c			\
					./src/menu/settings/sound/sfx/event/off.c			\
					./src/menu/settings/sound/music/button/on.c			\
					./src/menu/settings/sound/music/button/off.c		\
					./src/menu/settings/sound/music/event/ceo.c			\
					./src/menu/settings/interaction/button/key.c		\
					./src/menu/settings/interaction/event/key.c			\
					./src/menu/inventory/button/event/ceo.c				\
					./src/menu/inventory/display/inventory.c			\
					./src/menu/inventory/init/values.c					\
					./src/menu/inventory/text/title.c					\
					./src/menu/inventory/button/rect/first.c			\
					./src/menu/inventory/button/rect/second.c			\
					./src/menu/inventory/button/rect/third.c			\
					./src/menu/inventory/button/rect/fourth.c			\
					./src/menu/inventory/button/rect/fifth.c			\
					./src/menu/inventory/button/rect/six.c				\
					./src/menu/char/init/values.c						\
					./src/menu/char/display/char.c						\
					./src/menu/char/button/event/ceo.c					\
					./src/menu/char/button/event/intel.c				\
					./src/menu/char/button/event/strength.c				\
					./src/menu/char/button/event/speed.c				\
					./src/menu/char/button/player/left.c				\
					./src/menu/char/button/player/right.c				\
					./src/menu/char/button/player/sprite.c				\
					./src/menu/char/button/start/game.c					\
					./src/menu/char/button/start/char.c					\
					./src/menu/char/button/skills/intel.c				\
					./src/menu/char/button/skills/strength.c			\
					./src/menu/char/button/skills/speed.c				\
					./src/game/control_zone/control_zone.c				\
					./src/game/control_zone/collision.c					\
					./src/game/factory/factory_basement_collision.c		\
					./src/game/factory/factory_basement.c				\
					./src/game/factory/factory_collision.c				\
					./src/game/factory/factory.c						\
					./src/game/logos/entrance_collision.c				\
					./src/game/logos/entrance.c							\
					./src/game/logos/office_collision.c					\
					./src/game/logos/office.c							\
					./src/game/logos/machine_collision.c				\
					./src/game/logos/machine.c							\
					./src/game/safe_place/collision.c					\
					./src/game/safe_place/safe_place.c					\
					./src/game/map/map.c								\
					./src/game/map/collision.c							\
					./src/game/scene/change/single_scene.c				\
					./src/game/scene/change/scene.c						\
					./src/game/scene/change/other_scene.c				\
					./src/game/scene/change/logos_intern_scene.c		\
					./src/game/scene/change/factory_scene.c				\
					./src/init/collectible/knife.c						\
					./src/init/collectible/collectibles.c				\
					./src/init/collectible/npc_texts.c					\
					./src/init/font.c									\
					./src/init/collectible/main_place_npc.c				\
					./src/tp/player_pos.c								\
					./src/fight/choices/place/back/attack.c				\
					./src/fight/choices/place/back/enemy.c				\
					./src/fight/choices/place/back/inventory.c			\
					./src/fight/choices/control/back/attack.c			\
					./src/fight/choices/control/back/enemy.c			\
					./src/fight/choices/control/back/inventory.c		\
					./src/fight/choices/place/validation/attack.c		\
					./src/fight/choices/place/validation/enemy.c		\
					./src/fight/choices/place/validation/inventory.c	\
					./src/fight/choices/place/validation/ceo.c			\
					./src/fight/choices/place/validation/first.c		\
					./src/fight/choices/control/validation/first.c		\
					./src/fight/choices/control/validation/attack.c		\
					./src/fight/choices/control/validation/enemy.c		\
					./src/fight/choices/control/validation/inventory.c	\
					./src/fight/choices/place/attack.c					\
					./src/fight/choices/place/enemy/enemy.c				\
					./src/fight/choices/place/enemy/dopplegangers.c		\
					./src/fight/choices/place/enemy/back_change.c		\
					./src/fight/choices/place/inventory.c				\
					./src/fight/choices/place/first.c					\
					./src/fight/choices/control/attack.c				\
					./src/fight/choices/control/enemy.c					\
					./src/fight/choices/control/inventory.c				\
					./src/fight/choices/control/first.c					\
					./src/fight/choices/choice.c						\
					./src/fight/init/choices/place/attack.c				\
					./src/fight/init/choices/place/enemy.c				\
					./src/fight/init/choices/place/enemy_turn.c			\
					./src/fight/init/choices/place/inventory.c			\
					./src/fight/init/choices/place/first.c				\
					./src/fight/init/choices/control/attack.c			\
					./src/fight/init/choices/control/enemy.c			\
					./src/fight/init/choices/control/enemy_turn.c		\
					./src/fight/init/choices/control/inventory.c		\
					./src/fight/init/choices/control/first.c			\
					./src/fight/init/choices/ceo.c						\
					./src/fight/init/fights.c							\
					./src/fight/init/place.c							\
					./src/fight/init/control.c							\
					./src/fight/init/player.c							\
					./src/fight/init/background.c						\
					./src/fight/init/hud/hud.c							\
					./src/fight/init/hud/player/life.c					\
					./src/fight/init/hud/player/mindfulness.c			\
					./src/fight/init/hud/player/speed.c					\
					./src/fight/init/hud/player/level.c					\
					./src/fight/init/hud/enemies/life.c					\
					./src/fight/init/hud/enemies/level.c				\
					./src/fight/init/hud/boss/life.c					\
					./src/fight/init/hud/boss/level.c					\
					./src/fight/init/hud/boss/mind.c					\
					./src/fight/init/hud/display/ceo.c					\
					./src/fight/init/hud/display/player/player.c		\
					./src/fight/init/hud/display/player/place/life.c	\
					./src/fight/init/hud/display/player/control/life.c	\
					./src/fight/init/hud/display/player/place/mind.c	\
					./src/fight/init/hud/display/player/control/mind.c	\
					./src/fight/init/hud/display/player/subfuncs.c		\
					./src/fight/init/hud/display/enemies.c				\
					./src/fight/init/hud/display/boss.c					\
					./src/fight/player/animation.c						\
					./src/fight/player/datas.c							\
					./src/fight/player/enemy/enemy.c					\
					./src/fight/player/enemy/control.c					\
					./src/fight/player/enemy/place.c					\
					./src/fight/player/fight.c							\
					./src/fight/player/fightscene/fightscene.c			\
					./src/fight/player/fightscene/place.c				\
					./src/fight/player/fightscene/control.c				\
					./src/init/scenes.c									\
					./src/menu/save/button/save_event.c					\
					./src/menu/save/button/open_event.c					\
					./src/menu/save/button/ceo_event.c 					\
					./src/menu/save/button/save.c						\
					./src/menu/save/button/open.c						\
					./src/menu/save/background.c						\
					./src/menu/save/display.c							\
					./src/menu/save/enter.c								\
					./src/menu/save/init.c								\
					./src/init/missions.c								\
					./src/missions_text/bar.c							\
					./src/missions_text/draw.c							\
					./src/missions_text/knife.c							\
					./src/missions_text/main_place.c					\
					./src/missions_text/find_safe_place.c				\
					./src/missions_text/control_zone.c					\
					./src/missions_text/do_fight.c						\
					./src/entities/draw_text_npc.c						\
					./src/entities/change_e_interaction_texture.c		\
					./src/init/collectible/bar_npc.c					\
					./src/entities/bar_npc.c							\
					./src/entities/map/display.c						\
					./src/entities/map/knife.c							\
					./src/entities/map/main_place_npc.c					\
					./src/entities/map_collectible_collision.c			\
					./src/entities/collectible_collision.c				\
					./src/init/collectible/second_npc_text.c			\
					./src/entities/safe_place_npc.c						\
					./src/init/collectible/safe_place.c					\
					./src/init/three_d_map.c							\
					./src/game/map/three_d_collisions.c					\
					./src/entities/control_zone_npc.c					\
					./src/init/collectible/control_zone.c				\
					./src/init/collectible/control_zone_npc_text.c		\
					./src/missions_text/back_safe_place.c				\
					./src/entities/back_safe_place_npc.c				\
					./src/init/collectible/back_safe_place_npc.c		\
					./src/init/collectible/mate_back_safe_place_npc.c	\
					./src/init/collectible/knife_inventory.c			\
					./src/game/map/tp.c									\
					./src/destroy/collectibles.c						\
					./src/destroy/font.c								\
					./src/destroy/npc.c									\
					./src/destroy/missions.c							\

OBJ			=		$(SRC:.c=.o)

CC 			= 		gcc

AUDIO 		= 		-lcsfml-audio

CSFML 		= 		-lcsfml-graphics -lcsfml-window -lcsfml-system -lm

CFLAGS 		= 		-I./include/ -L./lib/my/ -lmy $(CSFML) $(WFLAGS) $(AUDIO)

WFLAGS 		= 		-W -Wall -Wextra -Wshadow

MAKE_LIB 	=  		make -C ./lib/my

MAKE_CLEAN 	= 		make clean -C ./lib/my

CP 			= 		cp ./lib/my/include/my.h ./include/

CLEAN_LIB	=		lib/my/libmy.a

RM 			= 		rm -f

.c.o:
		@$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)
		@printf "\033[34m [Compilation]\033[39m %s\n" $(<:.c=.o)

all:    $(OBJ)
		@$(MAKE_LIB)
		@$(CC) -g -o $(NAME) $(OBJ) $(CFLAGS)
		@echo -e "\033[1;32m [Compilation of $(NAME) done !]\033[0m\n"
		@$(CP)

clean:
		@$(RM) $(OBJ)
		@printf "\033[31m [Delete] \033[39m%s\n" $(OBJ)
		@echo -e "\033[1;32m [Clean of $(NAME) done !]\n\033[0m"
		@$(MAKE_CLEAN)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(CLEAN_LIB)

re: fclean all


coding-style: fclean
		@clear
		@echo -e "\033[1;36m [Run coding style]\033[0m"
		@coding-style . . && cat coding-style-reports.log
		@echo -e "\033[1;36m [End of coding style]\033[0m"
		@rm -f coding-style-reports.log
