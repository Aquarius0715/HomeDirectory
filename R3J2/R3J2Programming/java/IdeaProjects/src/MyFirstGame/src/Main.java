package MyFirstGame.src;

import ddf.minim.AudioPlayer;
import ddf.minim.*;
import javafx.util.Pair;
import processing.core.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;

class Coordinate {
    private final int x;
    private final int y;
    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
}

public class Main extends PApplet {

    final int CHUNK_SIZE = 8;

    Minim minim;

    boolean moving_right;
    boolean moving_left;
    int vertical_momentum;
    int air_timer;

    String player_action;
    int player_frame;
    boolean player_flip;

    int grass_sound_timer;

    PImage grass_image;
    PImage dirt_image;
    PImage plant_image;
    ddf.minim.AudioPlayer jump_sound;
    ArrayList<AudioPlayer> grass_sounds;

    ArrayList<Integer> true_scroll;
    HashMap<String, PImage> animation_frames;
    HashMap<String, ArrayList<String>> animation_database;
    HashMap<Integer, PImage> tile_index;

    public ArrayList<Pair<Coordinate, Integer>> generate_chunk(int x, int y) {
        ArrayList<Pair<Coordinate, Integer>> chunk_data = new ArrayList<>();
        for (int x_pos = 0; x_pos < CHUNK_SIZE; x_pos++) {
            for (int y_pos = 0; y_pos < CHUNK_SIZE; y_pos++) {
                int target_x = x * CHUNK_SIZE + x_pos;
                int target_y = y * CHUNK_SIZE + y_pos;
                int tile_type = 0; // air
                int height = (int) noise((float) (target_x * 0.1)) * 5;
                if (target_y > 8 - height) {
                    tile_type = 2; // dirt
                } else if (target_y == 8 - height) {
                    tile_type = 1; // grass
                } else if (target_y == 8 - height - 1) {
                    if (new Random().nextInt(5) == 0) {
                        tile_type = 3; // plant
                    }
                }
                if (tile_type != 0) {
                    chunk_data.add(new Pair<>(new Coordinate(target_x, target_y), tile_type));
                }
            }
        }
        return chunk_data;
    }

    public ArrayList<String> load_animation(String path, ArrayList<Integer> frame_durations) {
        String animation_name = path.split("/")[1];
        ArrayList<String> animation_frame_data = new ArrayList<>();
        int n = 0;
        for (int frame : frame_durations) {
            String animation_frame_id = animation_name + "_" + str(n);
            String img_loc = path + "/" + animation_frame_id + ".png";
            // player_animations/idle/idle_0.png
            PImage animation_image = loadImage(img_loc);
            animation_frames.put(animation_frame_id, animation_image);
            for (int i = 0; i < frame; i++) {
                animation_frame_data.add(animation_frame_id);
            }
            n++;
        }
        return animation_frame_data;
    }

    @Override
    public void settings() {
        size(600, 400);
    }

    @Override
    public void setup() {
        fill(146F, 244F, 255F);

        minim = new Minim(this);

        moving_right = false;
        moving_left = false;
        vertical_momentum = 0;
        air_timer = 0;
        grass_image = loadImage("blocks/grass.png");
        dirt_image = loadImage("blocks/dirt.png");
        plant_image = loadImage("blocks/plant.png");
        jump_sound = minim.loadFile("sounds/jump.wav");
        grass_sounds = new ArrayList<>(Arrays.asList(minim.loadFile("sounds/grass_0.wav"), minim.loadFile("sounds/grass_1.wav")));
        for (AudioPlayer sound : grass_sounds) {
            sound.setVolume(0.2F);
        }

        player_action = "idle";
        player_frame = 0;
        player_flip = false;

        grass_sound_timer = 0;

        true_scroll = new ArrayList<>();
        animation_frames = new HashMap<>();
        animation_database = new HashMap<>();
        animation_database.put("run", load_animation("player_animations/run", new ArrayList<>(Arrays.asList(7, 7))));
        animation_database.put("idle", load_animation("player_animations/idle", new ArrayList<>(Arrays.asList(7, 7, 40))));
        tile_index = new HashMap<Integer, PImage>() {
            {
                put(1, grass_image);
                put(2, dirt_image);
                put(3, plant_image);
            }
        };
    }

    @Override
    public void draw() {
    }

    public static void main(String[] args){
        PApplet.main("MyFirstGame.src.Main");
    }
}