# Generated by Django 2.2.2 on 2019-06-17 00:52

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Todolist',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=60)),
                ('datetime', models.DateTimeField(auto_now_add=True)),
            ],
        ),
        migrations.CreateModel(
            name='Todoitem',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('description', models.CharField(max_length=200)),
                ('due_date', models.DateTimeField(null=True)),
                ('completed', models.BooleanField()),
                ('list', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='todoapp.Todolist')),
            ],
        ),
    ]