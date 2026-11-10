
#include "main.h"

float autoNum = 0;


static void Zack1(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target_obj(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;

        autoNum = 1;

        

 LV_IMAGE_DECLARE(Zack);
 lv_obj_clean(lv_screen_active());
 lv_obj_t* img = lv_image_create(lv_screen_active());
 lv_image_set_src(img, &Zack);

    }
 


}

static void Braiden1(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target_obj(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++; 

        autoNum = 2;


    LV_IMAGE_DECLARE(braiden);
  lv_obj_clean(lv_screen_active());
  lv_obj_t* img = lv_image_create(lv_screen_active());
  lv_image_set_src(img, &braiden);
    }
}

static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target_obj(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;

        //Clear the brain screen and create the auton page
        lv_obj_clean(lv_screen_active());

        //Screen title
          lv_obj_t * label = lv_label_create(lv_screen_active());
     lv_label_set_text(label, "Auton Page");
     lv_obj_set_style_text_color(lv_screen_active(), lv_color_hex(0xffffff), LV_PART_MAIN);
     lv_obj_set_style_text_font(label, &lv_font_montserrat_24, LV_PART_MAIN);
     lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);

     // Autobuttons
     //If you wanna add your own buttons go for it but this will have 8 presets for you

     //Auto 1

     lv_obj_t * btn = lv_button_create(lv_screen_active());     /*Add a button the current screen*/
     lv_obj_set_pos(btn, 10, 40);                            /*Set its position*/
     lv_obj_set_size(btn, 120, 50); /*Set its size*/
     lv_obj_add_event_cb(btn, Braiden1, LV_EVENT_ALL, NULL);  /*Assign a callback to the button*/
    
     lv_obj_t * label1 = lv_label_create(btn);          /*Add a label to the button*/
     lv_label_set_text(label1, "Braiden");                     //Auto Name
     lv_obj_center(label1);

     //Auto 2

     lv_obj_t * btn2 = lv_button_create(lv_screen_active());     /*Add a button the current screen*/
     lv_obj_set_pos(btn2, 10, 100);                            /*Set its position*/
     lv_obj_set_size(btn2, 120, 50); /*Set its size*/
     lv_obj_add_event_cb(btn2, Zack1, LV_EVENT_ALL, NULL);  /*Assign a callback to the button*/
    
     lv_obj_t * label2 = lv_label_create(btn2);          /*Add a label to the button*/
     lv_label_set_text(label2, "Zack");                     //Auto Name
     lv_obj_center(label2);
    
    }
}


void MainscreenInitialize(void)
{
    /*Change the active screen's background color*/
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x003a57), LV_PART_MAIN);

    /*Create a white label, set its text and align it to the center*/
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "Wildcat Brain Screen");
    lv_obj_set_style_text_color(lv_screen_active(), lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_24, LV_PART_MAIN);
    
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);

    //Create some buttons belonging to different pages 
    lv_obj_t * btn = lv_button_create(lv_screen_active());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 40);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50); /*Set its size*/
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);   /*Assign a callback to the button*/
    
    lv_obj_t * label2 = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label2, "Autons");                     /*Set the labels text*/
    lv_obj_center(label2);
}
