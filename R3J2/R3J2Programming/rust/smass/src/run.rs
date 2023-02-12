use diesel::dsl::exists;
use diesel::prelude::*;
use diesel::select;
use crate::models::{InsertSmassConfig, SmassConfig};
use crate::utils::establish_connection;
use crate::schema::smass_config::dsl::smass_config;

pub trait Run {
    fn on_enable(&self) {
        let connection = establish_connection();
        let is_first_run: i8 = select(
            exists(smass_config
                .filter(smass_config.eq(0)))
                .get_result(&connection));

        if is_first_run == 0 {
            let new_config = InsertSmassConfig {
                is_first_run: i8::from(0)
            };
            diesel::insert_into(smass_config)
                .values(new_config)
                .execute(&connection)
                .expect("Error saving new user");
        }
    }

    fn on_disable(&self);
}

struct

impl Running for dyn Run {

}