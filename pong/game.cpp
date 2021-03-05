#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_pos_x = 0.f;
float player_pos_y = 0.f;

internal void
simulate_game(Input* input) {
	clear_screen(0);
	if (is_down(BUTTON_UP)) player_pos_y += 1.f/75.f;
	if (is_down(BUTTON_DOWN)) player_pos_y -= 1.f/75.f;
	if (is_down(BUTTON_RIGHT)) player_pos_x += 1.f / 75.f;
	if (is_down(BUTTON_LEFT)) player_pos_x -= 1.f / 75.f;

	draw_rect(player_pos_x, player_pos_y, 10, 10, 16777215);
	draw_rect(40, 0, 20, 25, 16763135);
	draw_rect(-40, 0, 20, 25, 16763135);
}