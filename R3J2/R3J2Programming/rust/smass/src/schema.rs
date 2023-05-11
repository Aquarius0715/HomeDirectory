table! {
    login_data (id) {
        id -> Unsigned<Bigint>,
        login_id -> Varchar,
        login_password -> Varchar,
        permission -> Varchar,
    }
}

table! {
    person_data (uuid) {
        id -> Unsigned<Bigint>,
        uuid -> Varchar,
        family_uuid -> Varchar,
        sex -> Tinyint,
        first_name -> Varchar,
        last_name -> Varchar,
        birth_day -> Varchar,
        phone_number -> Varchar,
        tel_number -> Varchar,
        others -> Varchar,
    }
}

table! {
    smass_config (id) {
        id -> Unsigned<Bigint>,
        is_first_run -> Tinyint,
    }
}

allow_tables_to_appear_in_same_query!(
    login_data,
    person_data,
    smass_config,
);
