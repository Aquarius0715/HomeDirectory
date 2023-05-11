table! {
    person_data (id) {
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
