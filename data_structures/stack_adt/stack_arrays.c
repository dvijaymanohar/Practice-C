// https://users.encs.concordia.ca/~chvatal/notes/stack.html
// Implementing Stack as an array

typedef struct stack
{
  stack_object *array;
  int capacity;
  int count;
} stack;

stack *create_stack(void)
{
  stack *s;
  stack_object *object;
  s = (stack *) malloc(sizeof(stack));
  
  if (s == NULL)
  {
    printf("OUT OF MEMORY!\n");
    exit(1);
  }
  
  object = (stack_object *) malloc(sizeof(stack_object));
  
  if (object == NULL)
  {
    printf("OUT OF MEMORY!\n");
    exit(1);
  }
  
  s->array = object;
  s->count = 0;
  s->capacity = 1;
  return s;
}

boolean stack_is_empty(stack *s)
{
  return ((s->count == 0) ? TRUE : FALSE);
}

stack_object *top_of_stack(stack *s)
{
  if (stack_is_empty(s) == TRUE)
  {
    printf("TRIED TO FIND THE TOP OF AN EMPTY STACK!\n");
    exit(1);
  }
  
  return (s->array) + ((s->count) - 1);
}

void push_on_stack(stack *s, stack_object *object)
{
  stack_object *newarray;
  
  if (s->count == s->capacity)
    /* DOUBLE THE LENGTH OF THE ARRAY */
  {
    (s->capacity) *= 2;
    newarray = (stack_object *)
               realloc(s->array, (s->capacity) * sizeof(stack_object));
               
    if (newarray == NULL)
    {
      printf("OUT OF MEMORY!\n");
      exit(1);
    }
    
    s->array = newarray;
  }
  
  (s->array)[s->count] = *object;
  (s->count)++;
}

void pop_stack(stack *s)
{
  if (stack_is_empty(s) == TRUE)
  {
    printf("TRIED TO POP AN EMPTY STACK!\n");
    exit(1);
  }
  
  (s->count)--;
}