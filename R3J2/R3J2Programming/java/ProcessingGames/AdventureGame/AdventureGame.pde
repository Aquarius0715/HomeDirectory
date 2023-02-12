import processing.javafx.*;

import ddf.minim.AudioSnippet;
import ddf.minim.*;
import processing.core.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;

    final int CHUNK_SIZE = 16;

    Minim minim;
    float vertical_momentum;
    int air_timer;
    int grass_sound_timer;
    
    Player player;
    
    AudioSnippet jump_sound;
    ArrayList<AudioSnippet> grass_sounds;

    ArrayList<Float> true_scroll;
    ArrayList<Integer> scroll;
    ArrayList<BackObject> background_objects;
    
    HashMap<String, Boolean> isMoving;
    HashMap<String, ArrayList<Integer>> background_positions;
    HashMap<String, PImage> animation_frames;
    HashMap<String, ArrayList<Block>> game_map;
    HashMap<String, ArrayList<String>> animation_database;
    HashMap<Integer, PImage> tile_index;

    public ArrayList<Block> generate_chunk(int x, int y, int index) {
        ArrayList<Block> chunk_data = new ArrayList<>();
        for (int x_pos = 0; x_pos < CHUNK_SIZE; x_pos++) {
            for (int y_pos = 0; y_pos < CHUNK_SIZE; y_pos++) {
                int target_x = x * CHUNK_SIZE + x_pos;
                int target_y = y * CHUNK_SIZE + y_pos;
                int tile_type = 0; // air
                int height = int(noise((target_x * 0.1)) * index);
                if (target_y > 16 - height) {
                    tile_type = 2; // dirt
                } else if (target_y == 16 - height) {
                    tile_type = 1; // grass
                } else if (target_y == 16 - height - 1) {
                    if (new Random().nextInt(5) == 0) {
                        tile_type = 3; // plant
                    }
                }
                if (tile_type != 0) {
                    chunk_data.add(new Block(new Coordinate(target_x, target_y), tile_type));
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
    
    public int collision(Rect rect, ArrayList<Rect> tiles) {
      int hit_count = 0;
      for (Rect tile : tiles) {
        if (tile.x < (rect.x + rect.width) &&
            rect.x < (tile.x + tile.width) &&
            tile.y < (rect.y + rect.vertical) &&
            rect.y < (tile.y + tile.vertical))
        {
          hit_count++;
        }
      }
      return hit_count;
    }
    
    public Action change_action(String action_var, int frame, String new_value) {
       if (action_var != new_value) {
          action_var = new_value;
          frame = 0;
       }
       return new Action(action_var, frame);
    }
    
    public Move move(Rect rect, ArrayList<Float> movement, ArrayList<Rect> tiles) {
      int hit_count;
      HashMap<String, Boolean> collision_types = new HashMap<String, Boolean>() {
          {
            put("top", false);
            put("bottom", false);
            put("right", false);
            put("left", false);
          }
        };
        rect.y += movement.get(1);
        hit_count = collision(rect, tiles);
        for (int i = 0; i < hit_count; i++) {
           if (movement.get(1) > 0) {
             rect.y -= 1.0;
             collision_types.put("bottom", true);
           } else if (movement.get(1) < 0) {
             rect.y += 0.2;
             collision_types.put("top", true);
           }
        }
        
        rect.x += movement.get(0);
        hit_count = collision(rect, tiles);
        for (int i = 0; i < hit_count; i++) {
            if (movement.get(0) > 0) {
              rect.x -= 2.0;
              collision_types.put("right", true);
            } else if (movement.get(0) < 0) {
              rect.x += 2.0;
              collision_types.put("left", true); 
            }
        }
        return new Move(rect, collision_types);
    }
    
    public void set_character(ArrayList<Integer> scroll) {
      String player_img_id = animation_database.get(player.action).get(player.frame);
      PImage player_img = animation_frames.get(player_img_id);
      if (player.flip == true) {
         image(player_img,
               player.rect.x - scroll.get(0),
               player.rect.y - scroll.get(1) + (displayHeight / 2) + 8,
               -player_img.width,
               player_img.height);
      } else {
         image(player_img,
               player.rect.x - scroll.get(0),
               player.rect.y - scroll.get(1) + (displayHeight / 2) + 8,
               player_img.width,
               player_img.height);
      } 
    }
    
    public void generate_background() {
      Random rnd = new Random();
      ArrayList<Integer> right = background_positions.get("right");
      ArrayList<Integer> left = background_positions.get("left");
      for (int i = 0; i < 5; i++) {
        background_objects.add(new BackObject(rnd.nextInt(2) == 0 ? 0.25 : 0.5, new ArrayList<Integer>(Arrays.asList(right.get(i) + 512, displayHeight / (rnd.nextInt(5) + 2), rnd.nextInt(100) + 40, displayWidth)))); right.set(i, right.get(i) + 512);
        background_objects.add(new BackObject(rnd.nextInt(2) == 0 ? 0.25 : 0.5, new ArrayList<Integer>(Arrays.asList(left.get(i) - 512, displayHeight / (rnd.nextInt(5) + 2), rnd.nextInt(100) + 40, displayWidth)))); left.set(i, left.get(i) - 512);
      }
      background_positions.put("right", right);
      background_positions.put("left", left);
    }
    
    @Override
    public void settings() {
        fullScreen();
    }

    @Override
    public void setup() {
        minim = new Minim(this);
        
        vertical_momentum = 0.0F;
        air_timer = 0;
        background_positions = new HashMap<String, ArrayList<Integer>>() {
          {
            put("right", new ArrayList<Integer>(Arrays.asList(120, 280, 30, 130, 300)));
            put("left", new ArrayList<Integer>(Arrays.asList(120, 280, 30, 130, 300)));
          }
        };
        isMoving = new HashMap<String, Boolean>() {
          {
            put("right", false);
            put("left", false);
          }
        };
        jump_sound = minim.loadSnippet("sounds/jump.wav");
        grass_sounds = new ArrayList<>(Arrays.asList(minim.loadSnippet("sounds/grass_0.wav"), minim.loadSnippet("sounds/grass_1.wav")));
        for (AudioSnippet sound : grass_sounds) {
            sound.setVolume(0.2F);
        }        
        background_objects = new ArrayList<BackObject>();

        grass_sound_timer = 0;

        player = new Player("idle", 0, false, new Rect(100, -50, 5, 13));

        true_scroll = new ArrayList<>(Arrays.asList(0.0F, 0.0F));
        animation_frames = new HashMap<>();
        game_map = new HashMap<>();
        animation_database = new HashMap<>();
        animation_database.put("run", load_animation("player_animations/run", new ArrayList<>(Arrays.asList(7, 7))));
        animation_database.put("idle", load_animation("player_animations/idle", new ArrayList<>(Arrays.asList(7, 7, 40))));
        tile_index = new HashMap<Integer, PImage>() {
            {
              put(1, loadImage("blocks/grass.png"));
              put(2, loadImage("blocks/dirt.png"));
              put(3, loadImage("blocks/plant.png"));
              put(4, loadImage("blocks/stone.png"));
            }
        };
    }

    @Override
    public void draw() {
      background(146, 244, 255);
      if (grass_sound_timer > 0) {
         grass_sound_timer--; 
      }
      
      true_scroll.set(0, true_scroll.get(0) + (player.rect.x - true_scroll.get(0) - displayWidth / 2) / 20);
      true_scroll.set(1, true_scroll.get(1) + (player.rect.y - true_scroll.get(1) - 106) / 20);
      
      scroll = new ArrayList<Integer>(Arrays.asList(int(true_scroll.get(0)), int(true_scroll.get(1))));
      colorMode(RGB,256);
      noStroke();
      fill(7, 80, 75);
      rect(0, displayHeight / 2, displayWidth, displayHeight);
      for (BackObject back : background_objects) {
         Rect rect = new Rect(back.rect.get(0) - scroll.get(0) * back.type,
                              back.rect.get(1) - scroll.get(1) * back.type,
                              back.rect.get(2), 
                              back.rect.get(3));
         if (back.type == 0.5) {
            colorMode(RGB, 256);
            noStroke();
            fill(20, 170, 150);
            rect(rect.x, rect.y, rect.vertical, rect.width);
         } else {
            colorMode(RGB, 256);
            noStroke();
            fill(15, 76, 73);
            rect(rect.x, rect.y, rect.vertical, rect.width);
         }
      }
      ArrayList<Rect> tile_rects = new ArrayList<Rect>();
      for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 12; x++) {
          int target_x = x - 1 + int(Math.round(scroll.get(0) / (CHUNK_SIZE * 16)));
          int target_y = y - 1 + int(Math.round(scroll.get(1) / (CHUNK_SIZE * 16)));
          String target_chunk = str(target_x) + ";" + str(target_y);
          if (!(game_map.keySet().contains(target_chunk))) {
            game_map.put(target_chunk, generate_chunk(target_x, target_y, 10));
            generate_background();
          }
          for (Block block : game_map.get(target_chunk)) {
            image(tile_index.get(block.tile_type),
                  block.coordinate.x * 16 - scroll.get(0),
                  block.coordinate.y * 16 - scroll.get(1) + displayHeight / 2);
            if (block.tile_type == 1 || block.tile_type == 2) {
              tile_rects.add(new Rect(block.coordinate.x * 16 + 8,
                                      block.coordinate.y * 16 - 16,
                                      16, 16));
            }
          }
        }
      }
      
      ArrayList<Float> player_movement = new ArrayList<Float>(Arrays.asList(0.0F, 0.0F));
      if (isMoving.get("right") == true) {
         player_movement.set(0, player_movement.get(0) + 2);
      }
      if (isMoving.get("left") == true) {
         player_movement.set(0, player_movement.get(0) - 2);
      }
      player_movement.set(1, player_movement.get(1) + vertical_momentum);
      vertical_momentum += 0.2;
      if (vertical_momentum > 3) {
         vertical_momentum = 3; 
      }
      
      if (player_movement.get(0) == 0) {
         Action action = change_action(player.action, player.frame, "idle");
         player.action = action.action_var;
         player.frame = action.frame;
      }
      if (player_movement.get(0) > 0) {
         player.flip = false; 
         Action action = change_action(player.action, player.frame, "run");
         player.action = action.action_var;
         player.frame = action.frame;
      }
      if (player_movement.get(0) < 0) {
         player.flip = true;
         Action action = change_action(player.action, player.frame, "run");
         player.action = action.action_var;
         player.frame = action.frame;
      }
      
      Move move = move(player.rect, player_movement, tile_rects);
      player.rect = move.rect;
      HashMap<String, Boolean> collisions = move.collision_types;
      
      if (collisions.get("bottom") == true) {
          air_timer = 0;
          vertical_momentum = 0;
          if (player_movement.get(0) != 0) {
             if (grass_sound_timer == 0) {
                grass_sound_timer = 30;
                AudioSnippet audio = grass_sounds.get(new Random().nextInt(2));
                audio.rewind();
                audio.play();
         }
      }
    } else {
         air_timer++;
    } 
      player.frame++;
      if (player.frame >= animation_database.get(player.action).size()) {
        player.frame = 0;
      }
    set_character(scroll);
  }
  
      void keyPressed() {
        try {
          if (key == 'd') {
            isMoving.put("right", true);
          }
          if (key == 'a') {
            isMoving.put("left", true);
          }
          if (key == ' ') {
            if (air_timer < 6) {
              jump_sound.rewind();
              jump_sound.play();
              vertical_momentum = -5; 
          }
        }
      } catch (Exception e) {
        e.printStackTrace(); 
      }
    }
    
    void keyReleased() {
        if (key == 'd') {
           isMoving.put("right", false);
        }
        if (key == 'a') {
           isMoving.put("left", false); 
        }
    }
    
class Coordinate {
    final int x;
    final int y;
    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Player {
    String action;
    int frame;
    boolean flip;
    Rect rect;
    public Player(String action, int frame, boolean flip, Rect rect) {
      this.action = action;
      this.frame = frame;
      this.flip = flip;
      this.rect = rect;
    }
}

class Block {
   final Coordinate coordinate;
   final int tile_type;
   public Block(Coordinate coordinate, int tile_type) {
      this.coordinate = coordinate;
      this.tile_type = tile_type;
   }
}

class Rect {
  float x;
  float y;
  float vertical;
  float width;

  public Rect(float x, float y, float vertical, float width) {
     this.x = x;
     this.y = y;
     this.vertical = vertical;
     this.width = width;
  }
}

class BackObject {
  float type;
  ArrayList<Integer> rect;
  public BackObject(float type, ArrayList<Integer> rect) {
      this.type = type;
      this.rect = rect;
  }
}

class Move {
  Rect rect;
  HashMap<String, Boolean> collision_types;
  public Move(Rect rect, HashMap<String, Boolean> collision_types) {
    this.rect = rect;
    this.collision_types = collision_types;
  }
}

class Action {
   String action_var;
   int frame;
   public Action(String action_var, int frame) {
      this.action_var = action_var;
      this.frame = frame;
   }
}
