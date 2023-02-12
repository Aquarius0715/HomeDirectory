use diesel::prelude::*;
use rust_mysql::models::User;
use rust_mysql::schema::users;
use rust_mysql::utils::establish_connection;

fn main() {
    let connection = establish_connection();
    let users = users::dsl::users
        .filter(users::name.eq("updated"))
        .load::<User>(&connection)
        .expect("Error loading users");

    for user in users {
        println!("{:?}", user);
    }
}