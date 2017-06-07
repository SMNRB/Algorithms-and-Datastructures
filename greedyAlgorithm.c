#include <stdio.h>
#include <stdlib.h>

typedef struct container_ship container_ship;
typedef struct container container;
typedef enum container_type container_type;

enum container_type {
    LIGHT,
    MEDIUM,
    HEAVY,
};

struct container {
    container* next_container;
    int value;
    int weight;
};

struct container_ship {
    container* container;
    int max_loading_capacity;
    int current_weight;
};

/* Creates a new container ship */
container_ship* create_ship()
{
    container_ship* new_container_ship = (container_ship*)malloc(sizeof(container_ship));
    new_container_ship->max_loading_capacity = 1500;
    new_container_ship->current_weight = 0;

    return new_container_ship;
}

/* Creates a new light container */
container* create_light_container()
{
    container* new_container = (container*)malloc(sizeof(container));
    new_container->value = 700;
    new_container->weight = 700;

    return new_container;
}

/* Creates a new medium container */
container* create_medium_container()
{
    container* new_container = (container*)malloc(sizeof(container));
    new_container->value = 800;
    new_container->weight = 800;

    return new_container;
}

/* Creates a new heavy container */
container* create_heavy_container()
{
    container* new_container = (container*)malloc(sizeof(container));
    new_container->value = 1000;
    new_container->weight = 1000;

    return new_container;
}

/* Loads one container to the ship */
container_ship* load_ship(container_ship* ship, container_type type)
{
    if(ship == NULL)
    {
        perror("load_ship");
    }

    switch(type) {
        case LIGHT:

            if(ship->current_weight == 0)
            {
                container* new_container = create_light_container();
                new_container->next_container = NULL;
                ship->container = new_container;
                ship->current_weight += new_container->weight;
            }
            else
            {
                container* new_container = create_light_container();
                new_container->next_container = ship->container;
                ship->container = new_container;
                ship->current_weight += new_container->weight;

            }

            break;

        case MEDIUM:

            if(ship->current_weight == 0)
            {
                container* new_container = create_medium_container();
                new_container->next_container = NULL;
                ship->container = new_container;
                ship->current_weight += new_container->weight;
            }
            else
            {
                container* new_container = create_medium_container();
                new_container->next_container = ship->container;
                ship->container = new_container;
                ship->current_weight += new_container->weight;

            }

            break;

        case HEAVY:

            if(ship->current_weight == 0)
            {
                container* new_container = create_heavy_container();
                new_container->next_container = NULL;
                ship->container = new_container;
                ship->current_weight += new_container->weight;
            }
            else
            {
                container* new_container = create_heavy_container();
                new_container->next_container = ship->container;
                ship->container = new_container;
                ship->current_weight += new_container->weight;

            }

            break;

        default: perror("Unknown container type");
    }

    return ship;
}


int main(void) {

    int load_counter_one = 0;
    container_ship* ship_one = create_ship();

    /* Greedy algorithm */
    printf("\nFirst ship entering harbor...\n");
    while(ship_one->max_loading_capacity > ship_one->current_weight)
    {
        if((ship_one->max_loading_capacity - ship_one->current_weight) >= 1000)
        {
            load_ship(ship_one, HEAVY);
            load_counter_one += 1;
        }
        else if((ship_one->max_loading_capacity - ship_one->current_weight) >= 800)
        {
            load_ship(ship_one, MEDIUM);
            load_counter_one += 1;
        }
        else if((ship_one->max_loading_capacity - ship_one->current_weight) >= 700)
        {
            load_ship(ship_one, LIGHT);
            load_counter_one += 1;
        }
        else
        {
            printf("This ship is full and cannot load any more containers!\n");
            printf("There are currently [number %d] containers on the ship!\n", load_counter_one);
            printf("The ship capacity is %d, and there is %d capacity left on the ship!\n",ship_one->current_weight, ship_one->max_loading_capacity - ship_one->current_weight);
            break;
        }
    }

    /* Better solution */
    printf("\nSecond ship entering harbor...\n");
    int load_counter_two = 0;
    container_ship* ship_two = create_ship();

    load_ship(ship_two, MEDIUM);
    load_counter_two += 1;
    load_ship(ship_two, LIGHT);
    load_counter_two += 1;

    printf("This ship is full and cannot load any more containers!\n");
    printf("There are currently [number %d] containers on the ship!\n", load_counter_two);
    printf("The ship capacity is %d, and there is %d capacity left on the ship!\n",ship_two->current_weight, ship_two->max_loading_capacity - ship_two->current_weight);

    return EXIT_SUCCESS;
}
