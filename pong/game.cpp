#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_1_p, player_1_dp;
float player_2_p, player_2_dp;

internal void
simulate_game(Input* input, float dt) {
	clear_screen(16777215);
	draw_rect(0, 0, 90, 45, 0);

	float player_1_ddp = 0.f;
	if (is_down(BUTTON_UP)) player_1_ddp += 1000;
	if (is_down(BUTTON_DOWN)) player_1_ddp -= 1000;

	player_1_ddp -= player_1_dp * 10.f;

	player_1_p = player_1_p + player_1_dp * dt + player_1_ddp * dt * dt * 0.5f;
	player_1_dp = player_1_dp + player_1_ddp * dt;

	float player_2_ddp = 0.f;
	if (is_down(BUTTON_W)) player_2_ddp += 1000;
	if (is_down(BUTTON_S)) player_2_ddp -= 1000;

	player_2_ddp -= player_2_dp * 10.f;

	player_2_p = player_2_p + player_2_dp * dt + player_2_ddp * dt * dt * 0.5f;
	player_2_dp = player_2_dp + player_2_ddp * dt;

	draw_rect(0, 0, 1, 1, 16777215);

	draw_rect(80, player_1_p, 2.5, 12, 16777215);
	draw_rect(-80, player_2_p, 2.5, 12, 16777215);
}