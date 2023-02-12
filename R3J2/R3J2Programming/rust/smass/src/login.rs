use diesel::prelude::*;
use std::io;
use std::io::Read;
use crate::models::LoginData;
use crate::utils::establish_connection;
use crate::schema::login_data;

pub fn login() {

    let mut id = String::new();
    let mut password = String::new();

    print!("login_id: ");
    io::stdin().read_line(&mut id).unwrap();
    print!("password: ");
    io::stdin().read_line(&mut password).unwrap();

    let connection = establish_connection();

    let data = login_data::dsl::login_data
        .first::<LoginData>(&connection)
        .expect("Error loading login data");

    println!("{:?}", data);

}