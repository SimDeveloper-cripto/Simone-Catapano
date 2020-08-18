const app = new Vue({
    el: '#app', // Lavoriamo sull'elemento nell pagina con l'id "app" 
    data: {
        title: 'LISTA DI COSE DA FARE! 😄',
        newTodo: '',
        todos: [] // L'array che contiene ogni "todo" 
    },
    methods: {
        addTodo(){
            /* console.log(this.newTodo); */
            this.todos.push({ // Aggiungiamo il nuovo todo nel vettore todos
                title: this.newTodo, // Lo aggiorniamo
                done: false
            });
            this.newTodo = ''; // Per pulire il form
        },
        removeTodo(todo){
            const todoIndex = this.todos.indexOf(todo); // Cerchiamo il todo da cancellare nel vettore
            this.todos.splice(todoIndex, 1);
        }
    }
});